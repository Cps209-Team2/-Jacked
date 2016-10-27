#ifndef WEAPON_H
#define WEAPON_H
#include <QString>

class Weapon
{
protected:
    QString type;//melee or ranged
public:
    Weapon(QString name) : type(name)
    {
        type = name;
    }

    void execute();
    QString getType() { return type; }

    ~Weapon() { }
};

#endif // WEAPON_H
