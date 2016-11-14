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
    double score = 0;

    QString name;

    Weapon *weapon;

    bool movRight;
    bool movLeft;

    int jumpDuration;
    int jumpSpeed;
    bool _rise;
    bool jumping;
    bool falling;
    bool grounded;

    bool attacking;
    int attackDuration;
    int atkBuffer;

    bool crouching;

public:
    Player(int initx, int inity, Weapon *item);
    Player() {}

    bool isPlayer() { return true; }
    bool isEnemy() { return false; }

    // MOVEMENT
    // moves left or right by 11 pixels
    void moveLeft();
    void moveRight();

    // getters and setters for moving and direction
    bool movingLeft() { return movLeft; }
    bool movingRight() { return movRight; }
    void turnLeft() { movLeft = true; movRight = false; }
    void turnRight() { movLeft = false; movRight = true; }
    void stopMoving();

    // JUMPING
    //getters and setters
    bool isJumping() { return jumping; }
    void setJump(bool jump) { jumping = jump; }

    bool jump(); // rises and falls in a set pattern
    // getters and setters
    bool rise() { return _rise; }
    bool isFalling() { return falling; }
    void setGrounded(bool g) { grounded = g; }
    bool isGrounded() { return grounded; }
    //getters and setter for determining where in the jump pattern the player is
    int getJS() { return jumpSpeed; }
    int getJD() { return jumpDuration; }
    void setJS(int y) { jumpSpeed = y; }
    void setJD(int y) { jumpDuration = y; }

    //CROUCHING
    void crouch() { crouching = true; }
    void stand() { crouching = false; }
    bool isCrouching() { return crouching; }

    //SAVE
    void saveScore(QFile *file);
    void saveState(QFile *file);

    //ATTACKING
    int getAttackDur() { return attackDuration; }
    void setAttack(bool atk) { attacking = atk; }
    bool isAttacking() { return attacking; }
    bool attack();
    int getHP() { return HP; }
    // getters and setters for weapon and DMG
    Weapon* getWeapon() { return weapon; }
    int getDmg() { return weapon->getDMG(); }

    //comments required by Bill, Kyle
    QString getName() { return name; }
    void setName(QString initName) { name = initName; }
    void addScore(double initScore);
    double getScore() { return score; }
    QString showHealth();

    ~Player();
};

#endif // PLAYER_H
