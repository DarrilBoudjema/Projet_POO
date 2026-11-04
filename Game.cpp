#include "Game.h"
#include "Player.h"
#include "Entity.h"
#include <vector>
#include <string>
#include <iostream>

Game* Game::instance = nullptr;

Game* Game::GetInstance() {
    if (instance == nullptr)
        instance = new Game();
    return instance;
}

void Game::Run()
{
    currentMap = new Map();
    currentMap->LoadFromFile("level/level1.txt");
    player = new Player();
    player->setAvatar('H');

    bool running = true;
    while (running) {
        system("cls"); // #include <cstdlib>

        if (player != nullptr) {
            // 1. On récupère la touche et la direction voulue
            int input = player->readPlayerInputs();
            char touch = (char)input;

            if (touch == 'x' || touch == 'X') {
                running = false;
                continue;
            }

            Vector2 dir = player->getDirections(input);
            Vector2 nextPos = player->getPosition() + dir;

            // 2. On vérifie que la position future est bien dans la carte
            if (nextPos.x >= 0 && nextPos.x < currentMap->width &&
                nextPos.y >= 0 && nextPos.y < currentMap->height)
            {
                const TileInfo& tileInfos = currentMap->GetTileInfo(nextPos.x, nextPos.y);
                
                if (tileInfos.symbol == '.') {
                    player->Move(dir); // Sol normal autorisé  
                }
                if (tileInfos.symbol == 'E') {                                     // Pour obtenir les collisions avec les ennemis il fait écrire ici 
                    system("cls");
                    std::cout << "Vous avez atteint la sortie !" << std::endl;
                  std :: cin.ignore();
                    std :: cin.get();

                }
            }
        }
        Render();

        std::string exitInput;
        std::getline(std::cin, exitInput);
        if (!exitInput.empty() && exitInput[0] == 'x')
            running = false;
    }
}


void Game::Render() const {
    std::vector<std::string> screen(currentMap->height,
        std::string(currentMap->width, ' '));

    for (int y = 0; y < currentMap->height; y++)
        for (int x = 0; x < currentMap->width; x++)
            screen[y][x] = currentMap->GetTileInfo(x, y).symbol;
    if (player != nullptr) {
        Vector2 playerPos = player->getPosition();
        if (playerPos.x >= 0 && playerPos.x < currentMap->width &&
            playerPos.y >= 0 && playerPos.y < currentMap->height)
            screen[playerPos.y][playerPos.x] = player->getAvatar();
    }
    // 3. Affichage
    for (const std::string& line : screen) {
        for (char c : line)
            std::cout << c << ' ';
        std::cout << '\n';
    }
}

void Game::DestroyInstance() {
    delete instance;              // appelle ~Game(), qui delete currentMap
    instance = nullptr;
}

