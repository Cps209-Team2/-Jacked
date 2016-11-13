#ifndef WEAPON_H
#define WEAPON_H
#include <QString>

class Weapon
{
protected:
    QString type;// type determines DMG
    int DMG;
public:
    Weapon(QString name);

    int getDMG() { return DMG; }
    QString getType() { return type; }

    ~Weapon() { }
};

#endif // WEAPON_H
