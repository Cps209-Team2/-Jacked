#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "weapon.h"

class Enemy: public Entity
{
    Weapon *weapon;
public:
    Enemy(int x, int y, Weapon *item);
    ~Enemy();

    Weapon* getWeapon() { return weapon; }
};

#endif // ENEMY_H
