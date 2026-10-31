#pragma once
class Entity
{

private:
	int life = 1;
	int damage = 1;
	char avatar = 'B';


public:

	void setAvatar(char newavatar) {
		avatar = newavatar;
	}

	char getAvatar() {
		return avatar;
	}

	// GetDirections()



};

