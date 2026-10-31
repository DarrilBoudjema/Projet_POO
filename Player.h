#pragma once
#include "Vector2.h"
#include "Entity.h"
class Player
{

public:
	int readPlayerInputs();
	Vector2 getDirections(int);
	virtual void OnUpdate() = 0;
};

