#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon
{
    std::string type;//melee or ranged
public:
    Weapon()
    {

    }

    void execute();
};

#endif // WEAPON_H
