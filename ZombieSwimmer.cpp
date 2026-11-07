#include "ZombieSwimmer.h"

ZombieSwimmer::ZombieSwimmer()
{
    setAvatar('S');
}

bool ZombieSwimmer::CanMove(const Vector2& pos) const
{
    if (!map) return false;

    if (pos.x < 0 || pos.x >= map->width || pos.y < 0 || pos.y >= map->height)
        return false;

    const TileInfo& tile = map->GetTileInfo(pos.x, pos.y);

    if (tile.isSwimmable)
        return HasOxygen();   // eau : seulement s'il lui reste de l'oxygène

    return tile.isWalkable;
}

void ZombieSwimmer::OnUpdate()
{
    Zombie::OnUpdate();   // même IA que le Zombie (utilise le CanMove redéfini)

    if (map)
        UpdateOxygen(IsInWater(*map, getPosition()));
}