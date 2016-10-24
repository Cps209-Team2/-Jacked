#ifndef CHARACTER_H
#define CHARACTER_H

#include "weapon.h"

class Character
{
    int HP;
    double xPos;
    double yPos;
    Weapon *tool;

public:

    Character(double initX, double initY, Weapon *initWeapon)
    {
        this->xPos = initX;
        this->yPos = initY;
        this->tool = initWeapon;
    }

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
    double getX() {return xPos;}
    double getY() {return yPos;}
    double getHp() {return HP;}
    Weapon getWeapon() {return *tool;}
//Setter methods
    void setX(double newX) {xPos =  newX;}
    void setY(double newY) {yPos =  newY;}
    void setHp(int newHP) {HP =  newHP;}
    //void setWeapon(Weapon newKit) {*tool =  newKit;}

virtual ~Character();
};

#endif // CHARACTER_H
