#include "player.h"
#include "entity.h"
#include <QRect>

Player::Player(int initx, int inity, Weapon *item)
{
    pos.setX(initx);
    pos.setY(inity);
    weapon = item;
    body = new QRect(pos.x(),pos.y(),50,50);

    jumpSpeed = 5;
}

void Player::save()
{
    //TODO Save the current player's position
}

// + and - seem backwards but are correct because y = 0 is at the top
bool Player::jump()
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

void Player::fall(int x)
{
    pos.setY(pos.y() + x);
}

