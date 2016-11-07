#ifndef COLLISION_H
#define COLLISION_H
#include <QRect>
#include <QDebug>
#include <QPoint>
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "collisioninfo.h"

class Collision
{
    Entity *_this;
    Entity *_that;
    bool collide;
    int xChange;
    QPoint *point;
    int x;
    int y;
public:
    Collision();

    Collision(Entity *obj1, Entity *obj2): _this(obj1),_that(obj2),collide(false),x(0),y(0) { }

    CollisionInfo *getData();

};

#endif // COLLISION_H
