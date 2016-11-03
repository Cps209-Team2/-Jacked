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
    int jumpHeight;

public:
    Player(int initx, int inity, Weapon *item);
    Player() {}

    bool isPlayer() { return true; }
    bool isEnemy() { return false; }
    void moveLeft();
    void moveRight();

    bool jump();
    void fall(int y);

    int getHP() { return HP; }
    int getJS() { return jumpSpeed; }
    void resetJS(int x) { jumpSpeed = 5; }

    Weapon* getWeapon() { return weapon; }
    void saveScore(QFile *file);

    ~Player();
    QString getName() { return name; }
    void setName(QString initName) { name = initName; }
    void setScore(double initScore);
    double getScore() { return score; }
};

#endif // PLAYER_H
