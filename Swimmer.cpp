#include "Swimmer.h"

bool Swimmer::HasOxygen() const
{
    return oxygen > 0;
}

bool Swimmer::IsInWater(const Map& map, const Vector2& pos) const
{
    return map.GetTileInfo(pos.x, pos.y).isSwimmable;
}

void Swimmer::UpdateOxygen(bool inWater)
{
    if (inWater) { if (oxygen > 0) oxygen--; }
    else { if (oxygen < maxOxygen) oxygen++; }
}