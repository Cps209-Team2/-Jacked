#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include "weapon.h"
#include "player.h"

class Enemy: public Entity
{
    Player *player;
    Weapon *weapon;
public:
<<<<<<< HEAD
    Enemy(int x, int y, Weapon *item, Player *obj);
    void move();
    void moveLeft();
    void moveRight();
=======
    Enemy(int x, int y, Weapon *item);
    ~Enemy();

>>>>>>> 77fa67c0c69b0d67ccdc76877da7ac59ad02fb44
    Weapon* getWeapon() { return weapon; }
};

#endif // ENEMY_H
