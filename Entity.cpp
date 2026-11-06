#include "Entity.h"

void Entity::setAvatar(char newavatar)
{
	avatar = newavatar;
}

char Entity::getAvatar()
{
	return avatar;
}

void Entity::Move(Vector2 direction)
{

	position = position + direction;


}


void Entity::Damage(Entity& attacker, int damage)
{
	attacker.life - damage;
}

bool Entity::isAlive()
{
	if (life < 0) {
		life = 0;
		return true;
	}
	return false;
}

bool Entity::isColliding(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2& dir, Vector2& player)
{
    // Implementation for collision detection
    return false;
}
