#ifndef ENTITY_H
#define ENTITY_H
#include <QDebug>
#include <QPoint>
#include <QRect>

class Entity
{
protected:
    QPoint pos;
    QRect *body;

public:
    Entity();
    Entity(int x, int y){ pos.setX(x); pos.setY(y); qDebug() << "created entity" << endl; }
    virtual void moveLeft(){ }
    virtual void moveRight() { }
    virtual QPoint getPos() { return pos; }

    ~Entity() { }
};

#endif // ENTITY_H
