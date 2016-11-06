#include "collision.h"

Collision::Collision()
{
}

int Collision::checkCollision()
{
    QRect a = QRect(_this->getPos(),_this->getSize());
    QRect b = QRect(_that->getPos(),_that->getSize());

    CollisionInfo *data = new CollisionInfo(0,0,_this,_that);

    crash = a.contains(b);

    bool rightSide = (a.contains(b.bottomLeft()) || a.contains(b.topLeft()));
    bool leftSide = (a.contains(b.bottomRight()) || a.contains(b.topRight()));
    bool topRight = (a.contains(b.bottomLeft()));
    bool botRight = (a.contains(b.topLeft()));
    bool topLeft = (a.contains(b.bottomLeft()));
    bool botLeft = (a.contains(b.topLeft()));


    if(rightSide)
    {
        xChange = -1 * (a.x() + a.width() - b.x()) - 95;
        if(_this->isPlayer() && _that->isEnemy())
        {
            _this->takeDmg(5);
        }

        crash = true;
        qDebug() << "ouch! -5 DMG" << endl;
    }
    if(leftSide)
    {
        xChange = b.x() - a.x() + a.width() + 95;
        if(_this->isPlayer() && _that->isEnemy())
        {
            _this->takeDmg(5);
        }

        crash = true;
        qDebug() << "ouch! -5 DMG" << endl;
    }
    if(topRight && botRight)
    {
        data->setX(_this->getPos().x() + -1 * (a.x() + a.width() - b.x()));
        data->setY(_this->getPos().y());
    }

    return xChange;
}
