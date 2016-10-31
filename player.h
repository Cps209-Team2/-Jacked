#ifndef PLAYER_H
#define PLAYER_H
#include <QDebug>
#include <QPoint>
#include <QRect>
#include <QFile>
#include <QTextStream>
#include <QString>
#include "entity.h"
#include "weapon.h"

class Player: public Entity
{
    Weapon *weapon;
    int jumpSpeed;
    QString name;
    double score;

public:
    Player(int initx, int inity, Weapon *item);
    Player() {}

    void moveLeft();
    void moveRight();

    bool jump();
    void fall(int x);

    int getJS() { return jumpSpeed; }
    void resetJS(int x) { jumpSpeed = 5; }

    Weapon* getWeapon() { return weapon; }
    void saveScore(QFile *file);
<<<<<<< HEAD

    ~Player();
=======
    QString getName() { return name; }
    void setScore(double initScore);
    double getScore() { return score; }
>>>>>>> 77fa67c0c69b0d67ccdc76877da7ac59ad02fb44
};

#endif // PLAYER_H
