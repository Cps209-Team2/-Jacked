#include "collision.h"

Collision::Collision()
{
}

int Collision::checkCollision()
{
    QRect a = QRect(_this->getPos(),_this->getSize());
    QRect b = QRect(_that->getPos(),_that->getSize());

    bool rightSide = (a.contains(b.bottomLeft()) || a.contains(b.topLeft()));
    bool leftSide = (a.contains(b.bottomRight()) || a.contains(b.bottomLeft()));

    int xCorrect;

    if(rightSide)
    {
        xCorrect = int(double(a.x() + a.width() - b.x()));
    }
    if(leftSide)
    {
        xCorrect = int(double(b.x() + b.width() - a.x()));
    }

    return xCorrect;
}
