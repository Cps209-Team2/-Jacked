#ifndef PLAYER_H
#define PLAYER_H
#include <QDebug>
#include <QPoint>
#include "entity.h"
#include "weapon.h"

class Player: public Entity
{
    Weapon *weapon;

public:
    Player(int initx, int inity, Weapon *item);
    Weapon* getWeapon() { return weapon; }
};

#endif // PLAYER_H
