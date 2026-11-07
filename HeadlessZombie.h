#pragma once
#include "Enemy.h"

class HeadlessZombie : public Enemy
{
public:
    HeadlessZombie();
    void OnUpdate() override;
};