#include "Warrior.h"

void Warrior::setAvatar(char newavatar)
{
	avatar = newavatar;
}


char Warrior::getAvatar()
{
	return avatar;
}

void Warrior::Damage(Warrior& attacker, int damage)
{
	attacker.life -= damage;
	attacker.damage = 2;
}

void Warrior::Move(Vector2 direction)
{
	position = position + direction;
}

bool Warrior::isAlive()
{
	if (life < 0) {
		life = 0;
		return true;
	}
	return false;
}

bool Warrior::isColliding(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2& dir, Vector2& player, Warrior& attacker, int damage, int& nextPos)
{
	// Implementation for collision detection
	return false;
}
