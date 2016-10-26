#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy:Character
{
    int type;

public:

    Enemy(int initX, int initY, Weapon *initWeapon, int initType):Character(initX, initY, initWeapon)
    {
        type = initType;
    }

    ~Enemy()
    {

    }

void move();
//moves based on player
void useWeapon();
//fires toward player
void setWeapon(Weapon);
//equips at lvl start
int takeDmg(int);
void die();
//removes object "tangibility"


};

#endif // ENEMY_H
