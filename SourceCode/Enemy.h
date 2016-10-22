#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
    int type;

public:

    Enemy(double initX, initY, Weapon *initWeapon, int initType):Character(initX, initY, initWeapon)
    {
        type = initType;
    }

move(keystroke*);
//moves based on player
useWeapon();
//fires toward player
setWeapon(Weapon);
//equips at lvl start
takeDmg(int);
die();
//removes object "tangibility"


};

#endif // ENEMY_H
