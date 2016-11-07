#include "collision.h"

Collision::Collision()
{
}

CollisionInfo *Collision::getData()
{
    QRect a = QRect(_this->getPos(),_this->getSize());
    QRect b = QRect(_that->getPos(),_that->getSize());

    collide = (a.right() > b.left()) || (a.left() < b.right()) || (a.top() < b.bottom()) || (a.bottom() > b.top());

    if(collide)
    {
        bool rightSide = (a.contains(b.bottomLeft()) || a.contains(b.topLeft()));
        bool leftSide = (a.contains(b.bottomRight()) || a.contains(b.topRight()));
        bool topRight = a.contains(b.bottomLeft());
        bool botRight = a.contains(b.topLeft());
        bool topLeft = a.contains(b.bottomLeft());
        bool botLeft = a.contains(b.topLeft());
        bool bot = a.contains(b) && (a.bottom() > b.top());
        bool top = a.contains(b) && (a.top() < b.bottom());

        /*
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
        */
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


        CollisionInfo *data = new CollisionInfo(x,y,_this,_that, collide);

        return data;
    }
    else
    {
        return NULL;
    }
}
