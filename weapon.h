#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon
{
    std::string type;//melee or ranged
public:
    Weapon(std::string name)
    {
    type = name;
    }

    void execute();
};

#endif // WEAPON_H
