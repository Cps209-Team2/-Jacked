#include "collisioninfo.h"

CollisionInfo::CollisionInfo()
{
}
CollisionInfo::CollisionInfo(int x, int y, Entity *ent1, Entity *ent2, bool crash)
{
    this->setX(x);
    this->setY(y);
    obj1 = ent1;
    obj2 = ent2;
    _collide = crash;
}
