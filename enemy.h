#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "weapon.h"
#include "player.h"

class Enemy: public Entity
{
    Player *player;
    Weapon *weapon;
public:
    Enemy(int x, int y, Weapon *item, Player *obj);
    void move();
    void moveLeft();
    void moveRight();
    Weapon* getWeapon() { return weapon; }
};

#endif // ENEMY_H
