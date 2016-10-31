#ifndef COLLISION_H
#define COLLISION_H
#include <QRect>
#include <QDebug>

class Collision
{
    QRect *a; //original object
    QRect *b; //colliding object
public:
    Collision();

    Collision(QRect *_a, QRect *_b)
    {
        a = _a;
        b = _b;
    }

    bool Collide()
    {
        if(a->intersects(*b))
        {
            qDebug() << "test" << endl;
        }
        return false;
    }
};

#endif // COLLISION_H
