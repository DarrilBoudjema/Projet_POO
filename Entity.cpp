#include "Entity.h"

void Entity::setAvatar(char newavatar)
{
	avatar = newavatar;
}

char Entity::getAvatar()
{
	return avatar;
}

void Entity::Damage(Entity& attacker, int damage)
{
	attacker.life - damage;
}

bool Entity::CanDead()
{
	if (life < 0) {
		life = 0;
		return true;
	}

	return false;
}




