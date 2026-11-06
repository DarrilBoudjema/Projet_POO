#include <iostream>
#include<conio.h>
#include "Mage.h"
#include"Player.h"
#include"Vector2.h"
#include"Game.h"
#include"TileInfo.h"

void Mage::setAvatar(char newavatar)
{
	avatar = newavatar;
}


char Mage::getAvatar()
{
	return avatar;
}

void Mage::Damage(Mage& attacker, int damage)
{
	attacker.life -= damage;
	attacker.damage = 1;
}

void Mage::Move(Vector2 direction)
{
	position = position + direction;
}

bool Mage::isAlive()
{
	if (life < 0) {
		life = 0;
		return true;
	}
	return false;
}

bool Mage::isColliding(Vector2 playerPos, Map* currentMap, std::vector<std::string>& screen, const TileInfo& tileInfos, Vector2& dir, Vector2& player, int damage, int& nextPos)
{
	
	return false;
}

void Mage::Special_Attack(Map* currentMap,Mage& attacker, const TileInfo& tileInfos, int damage, int Touch, int& nextPos,int& position)
{
	
	nextPos = (int)E_CellType::Ground ;

	char touch = (char)Touch;
	std::cin >> Touch;
	if (Touch == 32){
		if (nextPos == 'X') {
			attacker.life -= damage;
			attacker.damage = 3;
		}
		}

}