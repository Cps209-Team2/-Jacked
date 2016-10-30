#ifndef PLAYER_H
#define PLAYER_H
#include <QDebug>
#include <QPoint>
#include <QRect>
#include "entity.h"
#include "weapon.h"

class Player: public Entity
{
    Weapon *weapon;
    QRect *body;

public:
    Player(int initx, int inity, Weapon *item);
    Weapon* getWeapon() { return weapon; }
    void save();
};

#endif // PLAYER_H
