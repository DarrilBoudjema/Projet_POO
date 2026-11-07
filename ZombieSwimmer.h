#pragma once
#include "Zombie.h"
#include "Swimmer.h"

class ZombieSwimmer : public Zombie, public Swimmer
{
protected:
    bool CanMove(const Vector2& pos) const override;

public:
    ZombieSwimmer();
    void OnUpdate() override;
};