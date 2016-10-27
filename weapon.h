#ifndef WEAPON_H
#define WEAPON_H
#include <QString>

class Weapon
{
    QString type;//melee or ranged
public:

    Weapon(QString name)
    {
        type = name;
    }

    void execute();
};

#endif // WEAPON_H
