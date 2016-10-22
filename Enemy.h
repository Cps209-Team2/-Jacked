#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy:Character
{
    int type;

public:

    Enemy(double initX, double initY, Weapon *initWeapon, int initType):Character(initX, initY, initWeapon)
    {
        type = initType;
    }

//move(keystroke*);
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
