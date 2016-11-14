#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "entity.h"

// never became implemented
class Obstacle: public Entity
{
public:
    Obstacle(double initX, double initY)
    {
        pos.setX(initX);
        pos.setY(initY);
    }
};


#endif // OBSTACLE_H
