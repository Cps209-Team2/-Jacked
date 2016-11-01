#ifndef COLLISION_H
#define COLLISION_H
#include <QRect>
#include <QDebug>
#include "entity.h"
#include "player.h"
#include "enemy.h"

class Collision
{
    Entity *_this;
    Entity *_that;
    bool crash;
    int xChange;
public:
    Collision();

    Collision(Entity *obj1, Entity *obj2): _this(obj1),_that(obj2),crash(false),xChange(0) { }
    bool collide() { return crash; }

    int checkCollision();

};

#endif // COLLISION_H
