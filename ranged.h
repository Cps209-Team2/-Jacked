#ifndef RANGED_H
#define RANGED_H
#include "weapon.h"
#include <QString>

class Ranged: public Weapon
{
public:
    void execute();//creates projectile

    Ranged(QString _type):Weapon(type)//equippable on

    {

    }

    //all characters

    ~Ranged() {}
};

#endif // RANGED_H

