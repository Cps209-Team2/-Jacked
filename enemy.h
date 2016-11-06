#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "weapon.h"
#include "player.h"
#include "world.h"

class Enemy: public Entity
{
    Player *player;
    Weapon *weapon;
    bool enemy;
    bool start;
    int DMG;

public:
    Enemy() {}
    Enemy(int x, int y, Weapon *item, Player *obj);

    bool isEnemy() { return true; }
    bool isPlayer() { return false; }

    int getDMG() { return DMG; }

    void move();

    void moveLeft();
    void moveRight();


    //getters and setters
    Weapon* getWeapon() { return weapon; }
    void beginGame() {start = true;}
     ~Enemy();
};

#endif // ENEMY_H
