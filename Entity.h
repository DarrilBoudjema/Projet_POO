#pragma once
#include "Vector2.h"
class Entity
{

private:
	int life = 1;
	int damage = 1;
	char avatar = 'B';
	Vector2 position = Vector2(0, 0);


public:

	Entity() {};
	void setAvatar(char newavatar);

	char getAvatar();

	void Move(Vector2 direction);

	void Damage(Entity& attacker, int damage);

	bool isAlive();

	virtual void OnUpdate() = 0;

	virtual void onCollision() = 0;
};