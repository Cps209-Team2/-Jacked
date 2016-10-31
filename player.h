#ifndef PLAYER_H
#define PLAYER_H
#include <QDebug>
#include <QPoint>
#include <QRect>
#include <QFile>
#include <QTextStream>
#include "entity.h"
#include "weapon.h"

class Player: public Entity
{
    Weapon *weapon;
    int jumpSpeed;

public:
    Player(int initx, int inity, Weapon *item);

    void moveLeft();
    void moveRight();

    bool jump();
    void fall(int x);

    int getJS() { return jumpSpeed; }
    int resetJS(int x) { jumpSpeed = 5; }

    Weapon* getWeapon() { return weapon; }
    void saveScore(QFile *file);
};

#endif // PLAYER_H
