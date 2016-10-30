#include "player.h"
#include "entity.h"

Player::Player(int initx, int inity, Weapon *item)
{
    pos.setX(initx);
    pos.setY(inity);
    weapon = item;
}

void Player::save()
{
    //TODO Save the current player's position
}
