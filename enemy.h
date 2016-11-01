#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "weapon.h"
#include "player.h"

class Enemy: public Entity
{
    Player *player;
    Weapon *weapon;
    bool enemy;
    int DMG;
public:

    Enemy(int x, int y, Weapon *item, Player *obj);
    bool isEnemy() { return true; }
    bool isPlayer() { return false; }

    int getDMG() { return DMG; }

    void move();

    void moveLeft();
    void moveRight();

    ~Enemy();

    Weapon* getWeapon() { return weapon; }
};

#endif // ENEMY_H
