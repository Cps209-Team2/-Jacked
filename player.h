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
    int jumpSpeed;
    int gravity;

public:
    Player(int initx, int inity, Weapon *item);

    void jump();
    void fall();

    Weapon* getWeapon() { return weapon; }
    void save();
};

#endif // PLAYER_H
