#pragma once
#include "Entity.h"

class Enemy : public Entity
{
protected:
    Map* map = nullptr;
    const Entity* target = nullptr;   // le joueur

    static int Sign(int v);
    virtual bool CanMove(const Vector2& pos) const;

public:
    Enemy();
    void SetContext(Map* m, const Entity* t);

    void OnCollision(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen,
        const TileInfo& tileInfos, Vector2 dir, Vector2 player) override;
};