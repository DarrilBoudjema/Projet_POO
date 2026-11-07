#pragma once
#include "Vector2.h"
#include "Entity.h"

class Player : public Entity
{

public:
    int readPlayerInputs();
    Vector2 getDirections(int Touch);
    void OnUpdate() override;
    void OnCollision(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2 dir, Vector2 player) override;
    bool isColliding(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2 &dir, Vector2& player);
    void Special_Attack(Map* currentMap, Player& attacker, const TileInfo& tileInfos, int damage, int Touch, int& nextPos, int& position);
};