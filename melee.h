#ifndef MELEE_H
#define MELEE_H
#include <QString>
#include "weapon.h"

class Melee: public Weapon
{
public:
    void execute();//close range hitbox

    Melee(QString name):Weapon(type){}

    //equippable on all characters

    ~Melee();
};

#endif // MELEE_H
