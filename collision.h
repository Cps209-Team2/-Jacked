#ifndef COLLISION_H
#define COLLISION_H
#include <QRect>
#include <QDebug>
#include <entity.h>

class Collision
{
    Entity *_this;
    Entity *_that;
public:
    Collision();

    Collision(Entity *obj1, Entity *obj2)
    {
        _this = obj1;
        _that = obj2;
    }

    int checkCollision();

};

#endif // COLLISION_H