#ifndef RANGED_H
#define RANGED_H
#include <QString>
#include "weapon.h"

class Ranged: Weapon
{
public:
    void execute();//creates projectile

    Ranged(QString tool): Weapon(tool){

    }
    //equippable on

    //all characters

    ~Ranged();
};

#endif // RANGED_H

