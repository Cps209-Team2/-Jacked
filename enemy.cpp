#include "enemy.h"

Enemy::Enemy(int x, int y, Weapon *item)
{
    pos.setX(x);
    pos.setY(y);
    weapon = item;
}
