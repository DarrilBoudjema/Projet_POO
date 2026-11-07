#pragma once
#include <iostream>
#include "Entity.h"
#include "Vector2.h"
#include "Map.h"
class Warrior : private Entity 
{

	int life = 5;
	int damage = 2;
	char avatar = 'W';
	Vector2 position = Vector2(0, 0);





public:

	Warrior() {};
	void setAvatar(char newavatar);

	char getAvatar();

	void Move(Vector2 direction);


	void Damage(Warrior& attacker, int damage);

	bool isAlive();

	Vector2 getPosition() const { return position; }

	virtual void OnUpdate() = 0;

	virtual void OnCollision(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2 dir, Vector2 player) = 0;

	bool isColliding(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2& dir, Vector2& player, Warrior& attacker, int damage, int& nextPos);
};







