#pragma once
#include "Vector2.h"
#include "Map.h"

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

	Vector2 getPosition() const { return position; }

	virtual void OnUpdate() = 0;

	virtual void OnCollision(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2 dir, Vector2 player) = 0;

	bool isColliding(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2& dir, Vector2& player);
};
