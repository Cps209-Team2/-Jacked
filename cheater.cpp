#include "cheater.h"
#include "entity.h"
#include <QRect>

Cheater::Cheater(int initx, int inity, Weapon *item)
{
    pos.setX(initx);
    pos.setY(inity);
    weapon = item;
    body = new QRect(pos.x(),pos.y(),50,50);

    jumpSpeed = 5;
}
