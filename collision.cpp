#include "collision.h"

CollisionInfo *Collision::getData()
{
    QRect a = QRect(_this->getPos(),_this->getSize());
    QRect b = QRect(_that->getPos(),_that->getSize());

    bool rightSide = (a.contains(b.bottomLeft()) || a.contains(b.topLeft()));
    bool leftSide = (a.contains(b.bottomRight()) || a.contains(b.topRight()));
    bool topRight = a.contains(b.bottomLeft());
    bool botRight = a.contains(b.topLeft());
    bool topLeft = a.contains(b.bottomLeft());
    bool botLeft = a.contains(b.topLeft());
    bool bot = a.contains(b) && (a.bottom() > b.top());
    bool top = a.contains(b) && (a.top() < b.bottom());

    if(rightSide)
    {
        x = -1 * (a.right() - b.left());
        y = 0;
    }
    else if(leftSide)
    {
        x = b.right() - a.left();
        y = 0;
    }
    else if(topRight)
    {
        x = 1 * (a.x() + a.width() - b.x());
        y = a.top() - b.bottom();
    }
    else if(botRight)
    {
        x = -1 * (a.x() + a.width() - b.x());
        y = b.top() - a.bottom();
    }
    else if(topLeft)
    {
        x = b.x() - a.x() + a.width();
        y = a.top() - b.bottom();
    }
    else if(botLeft)
    {
        x = b.x() - a.x() + a.width();
        y = b.top() - a.bottom();
    }
    else if(top)
    {
        x = 0;
        y = a.top() - b.bottom();
    }
    else if(bot)
    {
        x = 0;
        y = b.top() - a.bottom();
    }

    if(x == 0 && y == 0)
        collide = false;
    else
        collide = true;

    CollisionInfo *data = new CollisionInfo(x,y,_this,_that, collide);
    return data;
}
