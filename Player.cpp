#include "Player.h"
#include "Vector2.h"
#include <iostream>
#include <conio.h>

int Player::readPlayerInputs()
{
    return _getch(); 
}

Vector2 Player::getDirections(int Touch)
{
    char touch = (char)Touch;
    

    if (touch == 'Z' || touch == 'z') {
        return Vector2(0, -1);
    }
    if (touch == 'S' || touch == 's') {
        return Vector2(0, 1);
    }
    if (touch == 'Q' || touch == 'q') {
        return Vector2(-1, 0);
    }
    if (touch == 'D' || touch == 'd') {
        return Vector2(1, 0);
    }

    return Vector2(0, 0);
} 

void Player::OnUpdate()
{
    int input = readPlayerInputs();
    Vector2 dir = getDirections(input);
    Move(dir);
}

void Player::OnCollision()
{
}