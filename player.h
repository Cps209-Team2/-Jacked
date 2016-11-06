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
    double score = 0;
    int DMG;
    int jumpDuration;
    bool _rise;
    bool falling;


public:
    Player(int initx, int inity, Weapon *item);
    //Player() {}

    bool isPlayer() { return true; }
    bool isEnemy() { return false; }
    void moveLeft();
    void moveRight();

    bool jump();
    bool rise() { return _rise; }
    bool isFalling() { return falling; }

    int getHP() { return HP; }
    int getJS() { return jumpSpeed; }
    int getJD() { return jumpDuration; }
    void setJS(int y) { jumpSpeed = y; }
    void setJD(int y) { jumpDuration = y; }


    Weapon* getWeapon() { return weapon; }
    void saveScore(QFile *file);
    void saveState(QFile *file);

    ~Player();
    QString getName() { return name; }
    void setName(QString initName) { name = initName; }
    void setScore(double initScore);
    double getScore() { return score; }
};

#endif // PLAYER_H
