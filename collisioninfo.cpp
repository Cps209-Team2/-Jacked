#include "collisioninfo.h"

CollisionInfo::CollisionInfo()
{
}
CollisionInfo::CollisionInfo(int X, int Y, Entity *ent1, Entity *ent2)
{
    point->setX(X);
    point->setY(Y);
    obj1 = ent1;
    obj2 = ent2;
}
