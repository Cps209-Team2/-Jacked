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
        xChange = -1 * (a.x() + a.width() - b.x()) - 65;
        if(_this->isPlayer() && _that->isEnemy())
        {
            _this->takeDmg(5);
        }

        crash = true;
        qDebug() << "ouch! -5 DMG" << endl;
    }
    if(leftSide)
    {
        xChange = b.x() - a.x() + a.width() + 65;
        if(_this->isPlayer() && _that->isEnemy())
        {
            _this->takeDmg(5);
        }

        crash = true;
        qDebug() << "ouch! -5 DMG" << endl;
    }

    return xChange;
}
