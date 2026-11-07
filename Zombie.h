#pragma once
#include "Enemy.h"

class Zombie : public Enemy
{
public:
    Zombie();
    void OnUpdate() override;
};