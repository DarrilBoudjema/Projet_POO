#pragma once
#include "Map.h"

class Swimmer
{
protected:
    int oxygen = 5;
    int maxOxygen = 5;

public:
    virtual ~Swimmer() = default;

    bool HasOxygen() const;
    bool IsInWater(const Map& map, const Vector2& pos) const;
    void UpdateOxygen(bool inWater);
};