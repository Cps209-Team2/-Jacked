#include "collision.h"

Collision::Collision()
{
}

int Collision::checkCollision()
{
    QRect a = QRect(_this->getPos(),_this->getSize());
    QRect b = QRect(_that->getPos(),_that->getSize());

    bool rightSide = (a.contains(b.bottomLeft()) || a.contains(b.topLeft()));
    bool leftSide = (a.contains(b.bottomRight()) || a.contains(b.topRight()));


    if(rightSide)
    {
        xChange = -1 * (a.x() + a.width() - b.x());
        crash = true;
        //qDebug() << "right" << endl;
    }
    if(leftSide)
    {
        xChange = b.x() - a.x() + a.width();
        crash = true;
        //qDebug() << "left" << endl;
    }

    return xChange;
}
