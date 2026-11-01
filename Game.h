#pragma once
#include "Entity.h"
#include "Map.h"
class Game
{
public:
    static Game* instance;
    static Game* GetInstance();
    static void DestroyInstance();
    static Game& Get() { static Game instance; return instance; }
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void Run();
    void Render() const;

private:
    Game() = default;
    ~Game() { delete currentMap; }

    Map* currentMap = nullptr;
    //Entity player;
    //std::vector<Entity> enemies;

};

