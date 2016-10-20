#ifndef CHARACTER_H
#define CHARACTER_H

#include "weapon"

class Character
{
    int HP;
    double xPos;
    double yPos;
    Weapon tool;

public:

    virtual void move(double, double) = 0;
    virtual void useWeapon() = 0;
    virtual void equipWeapon() = 0;
    virtual explicit void takeDamage(int) = 0;
    virtual void die() = 0;

    virtual ~Character()
    {

    }
};

#endif // CHARACTER_H
