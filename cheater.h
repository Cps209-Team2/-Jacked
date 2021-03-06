#ifndef CHEATER_H
#define CHEATER_H
#include <QDebug>
#include <QPoint>
#include <QRect>
#include "entity.h"
#include "weapon.h"
#include "player.h"

class Cheater: public Player
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

    ~Cheater() { delete weapon; }
};
#endif // CHEATER_H
