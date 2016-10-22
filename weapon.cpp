#include "weapon.h"
#include <string>

Weapon::Weapon()
{
    std::string type;//melee or ranged

    execute();
    //creates either melee or //ranged hitbox
}
