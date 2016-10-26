#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "weapon.h"

class Player:public Character
{

    double xPos;
    double yPos;
    Weapon *tool;
    double score;
public:

    Player(double initX, double initY, Weapon *initWeapon):Character(initX, initY, initWeapon)
    {
        score = 0;
    }

    ~Player() {

    }

    void move();
    //moves left or right
    void useWeapon();
    //uses equipped weapon
    void setWeapon(Weapon);
    //new weapon at each lvl
    int takeDmg(int);
    void die();
    //either restarts game or lvl

    void jump();
    //jumps player straight up
    void crouch();
    //lowers entity below //projectile level
};

#endif // PLAYER_H
