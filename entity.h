#ifndef ENTITY_H
#define ENTITY_H
#include <QDebug>
#include <QPoint>
#include <QRect>
#include <QSize>

class Entity
{
protected:
    QPoint pos;
    QRect *body;
    int HP;

public:
    Entity();
    Entity(int x, int y){ pos.setX(x); pos.setY(y); qDebug() << "created entity" << endl; }
    virtual void setX(int x) { pos.setX(x); }
    virtual void setY(int y) { pos.setY(y); }
    virtual QSize getSize() { return body->size(); }
    virtual void moveLeft(){ }
    virtual void moveRight() { }
    virtual QPoint getPos() { return pos; }
    virtual bool isEnemy() { return false; }
    virtual bool isPlayer() { return false; }

    virtual void takeDmg(int x) { HP -= x; }
    virtual int getDmg() { }

    virtual ~Entity();
};

#endif // ENTITY_H
