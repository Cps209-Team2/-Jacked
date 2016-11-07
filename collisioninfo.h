#ifndef COLLISIONINFO_H
#define COLLISIONINFO_H
#include "entity.h"
#include <QPoint>

class CollisionInfo
{
    int x;
    int y;
    Entity *obj1;
    Entity *obj2;
    bool _collide;

public:
    CollisionInfo();
    CollisionInfo(int x, int y, Entity *, Entity *,bool);

    int getX() { return x; }
    int getY() { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    Entity *getObj1() { return obj1; }
    Entity *getObj2() { return obj2; }
    bool collide() { return _collide; }


    ~CollisionInfo() { }
};

#endif // COLLISIONINFO_H
