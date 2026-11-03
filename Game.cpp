#include "Game.h"
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

    bool running = true;
    while (running) {
        system("cls");          // #include <cstdlib>
        Render();

        std::string input;
        std::getline(std::cin, input);
        if (!input.empty() && input[0] == 'x')
            running = false;
    }
}

void Game::Render() const {
    std::vector<std::string> screen(currentMap->height,
        std::string(currentMap->width, ' '));

    for (int y = 0; y < currentMap->height; y++)
        for (int x = 0; x < currentMap->width; x++)
            screen[y][x] = currentMap->GetTileInfo(x, y).symbol;

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
