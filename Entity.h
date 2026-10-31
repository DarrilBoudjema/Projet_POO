#pragma once
class Entity
{

private:
	int life = 1;
	int damage = 1;
	char avatar = 'B';


public:

	Entity() {};
	void setAvatar(char newavatar);

	char getAvatar();

	void Move();

	void Damage(Entity& attacker, int damage);

	bool isAlive();

	virtual void OnUpdate() = 0;

	virtual void onCollision() = 0;
};

