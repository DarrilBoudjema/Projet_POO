#include "Enemy.h"

Enemy::Enemy()
{
    setAvatar('X');
}

void Enemy::SetContext(Map* m, const Entity* t)
{
    map = m;
    target = t;
}

int Enemy::Sign(int v)
{
    return (v > 0) - (v < 0);
}

bool Enemy::CanMove(const Vector2& pos) const
{
    if (!map) return false;

    if (pos.x < 0 || pos.x >= map->width || pos.y < 0 || pos.y >= map->height)
        return false;

    return map->GetTileInfo(pos.x, pos.y).isWalkable;
}

void Enemy::OnCollision(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen,const TileInfo& tileInfos, Vector2 dir, Vector2 player)
{
    // À remplir : dégâts au joueur, etc.
}