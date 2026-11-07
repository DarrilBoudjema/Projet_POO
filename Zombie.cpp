#include "Zombie.h"
#include <cstdlib>   // std::abs

Zombie::Zombie()
{
    setAvatar('Z');
}

void Zombie::OnUpdate()
{
    if (!map || !target) return;

    Vector2 pos = getPosition();
    Vector2 diff = target->getPosition() - pos;

    // on avance sur l'axe où la distance est la plus grande
    Vector2 dir = (std::abs(diff.x) >= std::abs(diff.y))
        ? Vector2(Sign(diff.x), 0)
        : Vector2(0, Sign(diff.y));

    if (CanMove(pos + dir))   // bête : s'il est bloqué, il ne contourne pas
        Move(dir);
}