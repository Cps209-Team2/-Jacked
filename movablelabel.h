#ifndef MOVABLELABEL_H
#define MOVABLELABEL_H
#include <Qt>
#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>
#include "entity.h"
#include <QPixmap>
#include "enemy.h"
#include "accesslabel.h"

class MovableLabel:public QLabel, public AccessLabel
{
    Q_OBJECT

protected:

    QPixmap *img;
    Entity *obj;
    bool isHide;

public:
    explicit MovableLabel(QWidget* parent, Entity* object, QPixmap* pix);

    // changes img to new QPixMap with appropriate scaling and
    virtual void updateImg(QPixmap *);
    virtual QPixmap *pix() { return img; }

    // method from AccessLabel.  Hides when obj is dead
    virtual void hideLabel() { isHide = true; }
    virtual bool isHidden() { return isHide; }

    // directly moves obj
    virtual void updatePos() { this->move(obj->getPos()); }

    // invokes obj directional move methods
    virtual void movePos() { dynamic_cast<Enemy*>(obj)->move(); }
    virtual void moveLeft() { obj->moveLeft(); this->updatePos(); }
    virtual void moveRight() { obj->moveRight(); this->updatePos(); }

    // direction obj is facing, getters and setters
    virtual void faceRight() { obj->faceRight(); }
    virtual void faceLeft() { obj->faceLeft(); }
    virtual bool facingRight() { return obj->facingRight(); }
    virtual bool facingLeft() { return obj->facingLeft(); }

    // getters and setters for obj pos
    virtual QPoint getPos() { return obj->getPos(); }
    virtual void setPos(QPoint pos);
    virtual void setY(int y) { obj->setY(y); this->updatePos(); }
    virtual void setX(int x) { obj->setX(x); this->updatePos(); }
    virtual void getY() { obj->getPos().y(); }
    virtual void getX() { obj->getPos().x(); }

    Entity *object() { return obj; }

    virtual ~MovableLabel();

private slots:

};

#endif // MOVABLELABEL_H
