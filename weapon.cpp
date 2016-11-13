#include <QDebug>
#include "weapon.h"
#include <string>

Weapon::Weapon(QString name):type(name)
{
    if(name == "fist")
    {
        DMG = 5;
    }
}
