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
    void moveLeft() { pos.setX(pos.x() - 10); }
    void moveRight() { pos.setX(pos.x() + 10); }
    QPoint getPos() { return pos; }

    ~Entity() { }
};

#endif // ENTITY_H
