#ifndef ENTITY_H
#define ENTITY_H
#include <QDebug>
#include <QPoint>
#include <QRect>
#include <QSize>
#include <QFile>
#include "accesslabel.h"

class Entity
{
protected:
    QPoint pos;
    QRect *body;
    int HP;
    bool left;
    bool right;
    int DMG;
    int id;
    AccessLabel *label;


public:
    Entity();
    Entity(int x, int y){ pos.setX(x); pos.setY(y); qDebug() << "created entity" << endl; }

    virtual void setLabel(AccessLabel *lbl) { label = lbl; }

    virtual void hideLabel() { label->hideLabel(); }

    virtual int getId() { return id; }

    virtual void setX(int x) { pos.setX(x); }
    virtual void setY(int y) { pos.setY(y); }

    virtual void moveLeft(){ }
    virtual void moveRight() { }

    virtual QPoint getPos() { return pos; }
    virtual QSize getSize() { return body->size(); }
    virtual QRect getBody() { return *body; }
    virtual void setBody(QRect *temp) { body = temp; }

    virtual void faceRight() { right = true; left = false; }
    virtual void faceLeft() { left = true; right = false; }
    virtual bool facingRight() { return right; }
    virtual bool facingLeft() { return left; }

    virtual bool isEnemy() { return false; }
    virtual bool isPlayer() { return false; }

    virtual void takeDmg(int x) { HP -= x; }
    virtual int getDmg() { return DMG; }
    virtual int getHP() { return HP; }
    virtual void setHP(int health) { HP = health; }
    virtual void saveState (QFile *file) = 0;
    virtual void die() { body = new QRect(0,0,0,0); }
    virtual ~Entity();
};

#endif // ENTITY_H
