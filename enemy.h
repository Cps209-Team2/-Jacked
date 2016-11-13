#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "weapon.h"
#include "player.h"
#include "world.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

class Enemy: public Entity
{
    Player *player;
    Weapon *weapon;
    bool enemy;
    int moveSpeed;
    static int nextId;

public:
    Enemy() {}
    Enemy(int x, int y, Weapon *item, Player *obj, int ms);

    bool isPlayer() { return false; }
    bool isEnemy() { return true; }

    // enemy always follows player's current pos unless jumping or crouching
    void move();

    int getDmg() { return weapon->getDMG(); }

    // enemy position changing functions
    void moveLeft();
    void moveRight();

    // used to save current position and health of enemy
    void saveState(QFile *file);

    // getter
    Weapon* getWeapon() { return weapon; }

    ~Enemy();
};

#endif // ENEMY_H
