#include "HeadlessZombie.h"
#include <cstdlib>   // std::rand

HeadlessZombie::HeadlessZombie()
{
    setAvatar('H');
}

void HeadlessZombie::OnUpdate()
{
    static const Vector2 dirs[4] = { { 0, -1 },{ 0, 1 },{ -1, 0 },{ 1, 0 } };
    Vector2 dir = dirs[std::rand() % 4];

    if (CanMove(getPosition() + dir))
        Move(dir);
}