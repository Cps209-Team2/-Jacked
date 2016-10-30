#include "player.h"
#include "entity.h"
#include <QRect>

Player::Player(int initx, int inity, Weapon *item)
{
    pos.setX(initx);
    pos.setY(inity);
    weapon = item;
    body = new QRect(pos.x(),pos.y(),50,50);
}

void Player::save()
{
    //TODO Save the current player's position
}

void Player::save()
{
    //TODO Save the current player's position
}
