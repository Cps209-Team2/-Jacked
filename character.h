#ifndef CHARACTER_H
#define CHARACTER_H

#include "weapon.h"

class Character
{
    int HP;
    int xPos;
    int yPos;
    Weapon *tool;

public:

    Character(int initX, int initY, Weapon *initWeapon)
    {
        this->xPos = initX;
        this->yPos = initY;
        this->tool = initWeapon;
    }

virtual ~Character() { }

virtual void move();
//moves entity
virtual void useWeapon();
//triggers Weapon object execute()
virtual void setWeapon(Weapon*);
//equip weapon object to character
virtual int takeDmg(int);
//lowers character hp
virtual void die();
//removes entity from map

//Getter methods
    int getX() {return xPos;}
    int getY() {return yPos;}
    int getHp() {return HP;}
    Weapon getWeapon() {return *tool;}
//Setter methods
    void setX(int newX) {xPos =  newX;}
    void setY(int newY) {yPos =  newY;}
    void setHp(int newHP) {HP =  newHP;}
    //void setWeapon(Weapon newKit) {*tool =  newKit;}


};

#endif // CHARACTER_H
