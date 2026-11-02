#pragma once
#include "Entity.h"
#include "Vector2.h"

class Player : public Entity
{
public:
    int readPlayerInputs();
    Vector2 getDirections(int Touch);
    void OnUpdate() override;
    void OnCollision() override; 
};