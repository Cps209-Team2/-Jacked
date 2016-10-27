#ifndef ENTITY_H
#define ENTITY_H
#include <QDebug>
#include <QPoint>

class Entity
{
protected:
    QPoint pos;

public:
    Entity();
    Entity(int x, int y){ pos.setX(x); pos.setY(y); qDebug() << "created entity" << endl; }
    virtual void moveLeft() { pos.setX(pos.x() - 10); }
    virtual void moveRight() { pos.setX(pos.x() + 10); }
    virtual QPoint getPos() { return pos; }

    ~Entity() { }
};

#endif // ENTITY_H
