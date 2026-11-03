#pragma once
#include "Vector2.h"
#include "Entity.h"

class Player : public Entity
{

public:
    int readPlayerInputs();
    Vector2 getDirections(int Touch);
    void OnUpdate() override;
    void OnCollision() override;
};