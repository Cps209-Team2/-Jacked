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

    void moveLeft();
    void moveRight();

    bool jump();
    void fall(int x);

    int getJS() { return jumpSpeed; }
    int resetJS(int x) { jumpSpeed = 5; }

    Weapon* getWeapon() { return weapon; }
    void save();
};
#endif // CHEATER_H
