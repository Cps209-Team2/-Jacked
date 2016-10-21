#ifndef PLAYER_H
#define PLAYER_H

//#include "character.h"

class Player: public Character
{

public:
    move(keystroke);
    //moves left or right
    useWeapon();
    //uses equipped weapon
    setWeapon(Weapon);
    //new weapon at each lvl
    takeDmg(int);
    die();
    //either restarts game or lvl

    jump();
    //jumps player straight up
    crouch();
    //lowers entity below //projectile level
};

#endif // PLAYER_H
