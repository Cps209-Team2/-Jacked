#ifndef COLLISIONINFO_H
#define COLLISIONINFO_H
#include "entity.h"
#include <QPoint>

class CollisionInfo
{
    QPoint *point;
    Entity *obj1;
    Entity *obj2;

public:
    CollisionInfo();
    CollisionInfo(int, int, Entity *, Entity *);

    QPoint *getPoint() { return point; }
    void setX(int x) { point->setX(x); }
    void setY(int y) { point->setY(y); }
    Entity *getObj1() { return obj1; }
    Entity *getObj2() { return obj2; }


    ~CollisionInfo() { }
};

#endif // COLLISIONINFO_H
