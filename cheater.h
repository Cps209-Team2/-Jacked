#ifndef CHEATER_H
#define CHEATER_H
#include <QDebug>
#include <QPoint>
#include <QRect>
#include "entity.h"
#include "weapon.h"

class Cheater: public Entity
{
    Weapon *weapon;
    int jumpSpeed;
    int gravity;

public:
    Cheater(int initx, int inity, Weapon *item);

    void jump();
    void fall();

    Weapon* getWeapon() { return weapon; }
    void save();
};
#endif // CHEATER_H
