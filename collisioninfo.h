#ifndef COLLISIONINFO_H
#define COLLISIONINFO_H
#include "entity.h"
#include <QPoint>

class CollisionInfo
{    
    Entity *obj1;
    Entity *obj2;

    // tests if the objects collided
    bool _collide;

    // distance of overlap
    int x;
    int y;

public:
    CollisionInfo() { }
    CollisionInfo(int x, int y, Entity *, Entity *,bool);

    // getters
    int getX() { return x; }
    int getY() { return y; }
    Entity *getObj1() { return obj1; }
    Entity *getObj2() { return obj2; }
    bool collide() { return _collide; }

    // setters
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    ~CollisionInfo() { }
};

#endif // COLLISIONINFO_H
