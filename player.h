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
#include "collisioninfo.h"

class Player: public Entity
{
    Weapon *weapon;
    QString name;
    double score = 0;
    int jumpDuration;
    int jumpSpeed;
    CollisionInfo *knockback;
    bool _rise;
    bool falling;
    bool attacking;
    int attackDuration;
    int atkBuffer;

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

    void recoil(CollisionInfo *);

    Weapon* getWeapon() { return weapon; }
    void saveScore(QFile *file);
    void saveState(QFile *file);

    bool setAttack(bool atk) { attacking = atk; }
    bool isAttacking() { return attacking; }
    bool attack();

    ~Player();
    QString getName() { return name; }
    void setName(QString initName) { name = initName; }
    void setScore(double initScore);
    double getScore() { return score; }
};

#endif // PLAYER_H
