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
    bool crouching;
    bool hit;
    bool grounded;
    bool movRight;
    bool movLeft;

public:
    Player(int initx, int inity, Weapon *item);
    Player() {}

    bool isPlayer() { return true; }
    bool isEnemy() { return false; }
    void moveLeft();
    void moveRight();
    bool movingLeft() { return movLeft; }
    bool movingRight() { return movRight; }
    void turnLeft() { movLeft = true; movRight = false; }
    void turnRight() { movLeft = false; movRight = true; }
    void stopMoving();

    bool jump();
    bool rise() { return _rise; }
    bool isFalling() { return falling; }

    int getHP() { return HP; }
    int getJS() { return jumpSpeed; }
    int getJD() { return jumpDuration; }
    void setJS(int y) { jumpSpeed = y; }
    void setJD(int y) { jumpDuration = y; }
    void crouch() { crouching = true; }
    void stand() { crouching = false; }
    bool isCrouching() { return crouching; }

    void recoil(CollisionInfo *);

    Weapon* getWeapon() { return weapon; }
    void saveScore(QFile *file);
    void saveState(QFile *file);

    int getAttackDur() { return attackDuration; }
    void setGrounded(bool g) { grounded = g; }
    bool isGrounded() { return grounded; }
    void setAttack(bool atk) { attacking = atk; }
    bool isAttacking() { return attacking; }
    bool attack();
    void setHit(bool smack) { hit = smack; }
    bool isHit() { return hit; }
    ~Player();
    QString getName() { return name; }
    void setName(QString initName) { name = initName; }
    void setScore(double initScore);
    double getScore() { return score; }
    QString showHealth();
};

#endif // PLAYER_H
