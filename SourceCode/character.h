#ifndef CHARACTER_H
#define CHARACTER_H

#include "weapon"

class Character
{
    int HP;
    double xPos;
    double yPos;
    Weapon *tool;

public:

public:
virtual move(keystroke*);
//moves entity
virtual useWeapon();
//triggers Weapon object execute()
virtual setWeapon(Weapon*);
//equip weapon object to character
virtual takeDmg(int);
//lowers character hp
virtual die();
//removes entity from map

virtual ~Character();
};

#endif // CHARACTER_H
