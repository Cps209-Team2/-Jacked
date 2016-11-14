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

    // tests whether this and that actuallt collided
    bool collide;

    // distance of overlap between the this and that
    int x;
    int y;
public:

    Collision() { }

    Collision(Entity *obj1, Entity *obj2): _this(obj1),_that(obj2),collide(false),x(0),y(0) { }

    // tests if the bodies (QRect) of each entity overlap, and by how much.  Returns a packet with information
    CollisionInfo *getData();

};

#endif // COLLISION_H
