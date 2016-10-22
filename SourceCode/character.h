#ifndef CHARACTER_H
#define CHARACTER_H

#include "weapon.h"

class Character
{
    int HP;
    double xPos;
    double yPos;
    Weapon *tool;

public:

    Character(double initX, double initY, Weapon *initWeapon)
    {

    }

//virtual move(keystroke*);
//moves entity
virtual void useWeapon();
//triggers Weapon object execute()
virtual void setWeapon(Weapon*);
//equip weapon object to character
virtual int takeDmg(int);
//lowers character hp
virtual void die();
//removes entity from map

virtual ~Character();
};

#endif // CHARACTER_H
