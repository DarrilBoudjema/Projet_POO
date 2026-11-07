#pragma once
#include "Entity.h"
class Mage : private Entity
{


	int life = 1;
	int damage = 1;
	char avatar = 'M';
	Vector2 position = Vector2(0, 0);


public:

	Mage() {};
	void setAvatar(char newavatar);

	char getAvatar();

	void Move(Vector2 direction);


	void Damage(Mage& attacker, int damage);

	bool isAlive();

	Vector2 getPosition() const { return position; }


	virtual void OnUpdate() = 0;

	virtual void OnCollision(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2 dir, Vector2 player) = 0;

	bool isColliding(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2& dir, Vector2& player, int damage, int& nextPos);

	void Special_Attack(Map* currentMap,Mage& attacker, const TileInfo& tileInfos, int damage, int Touch, int& nextPos,int& position);
};



