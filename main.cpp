#include <iostream>
#include "Game.h"

int main() {
    
    Game* game = Game::GetInstance();
    game->Run();
    // on oublie pas de delete dans le destructeur
    return 0;
    
}