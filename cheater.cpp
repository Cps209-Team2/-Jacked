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

void Cheater::moveLeft()
{
    pos.setX(pos.x() - 12);
    body->moveTo(pos);
}


void Cheater::moveRight()
{
    pos.setX(pos.x() + 12);
    body->moveTo(pos);
}

void Cheater::save()
{
    //TODO Save the current player's position
}

// + and - seem backwards but are correct because y = 0 is at the top
bool Cheater::jump()
{
    if(jumpSpeed > 0)
    {
        pos.setY(pos.y() - jumpSpeed);
        --jumpSpeed;
        return true;
    }
    else if(jumpSpeed == 0)
    {
        jumpSpeed == 5;
        return false;
    }
}

void Cheater::fall(int x)
{
    pos.setY(pos.y() + x);
}



