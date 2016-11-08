#ifndef ENTITY_H
#define ENTITY_H
#include <QDebug>
#include <QPoint>
#include <QRect>
#include <QSize>
#include <QFile>

class Entity
{
protected:
    QPoint pos;
    QRect *body;
    int HP;
    bool left;
    bool right;
    int DMG;

public:
    Entity();
    Entity(int x, int y){ pos.setX(x); pos.setY(y); qDebug() << "created entity" << endl; }

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
<<<<<<< HEAD
    virtual int getHP() { return HP; }
    virtual void setHP(int health) { HP = health; }
=======
    virtual void saveState (QFile *file) = 0;

>>>>>>> 1b4a2afa585f394e2fd51fa3d531d7684562ab69
    virtual ~Entity();
};

#endif // ENTITY_H
