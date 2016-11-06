#ifndef MOVABLELABEL_H
#define MOVABLELABEL_H
#include <Qt>
#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>
#include "entity.h"
#include <QPixmap>

class MovableLabel:public QLabel
{
    Q_OBJECT

protected:

    QPixmap *img;
    Entity *obj;

public:
    explicit MovableLabel(QWidget* parent, Entity* object, QPixmap* pix): QLabel(parent), obj(object), img(pix)
    {
        if(obj->isPlayer())
            this->setPixmap(pix->scaled(QSize(68,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
        else
            this->setPixmap(pix->scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }

    virtual void updateImg(QPixmap *);

    // directly moves obj
    virtual void updatePos() { this->move(obj->getPos()); }

    // invokes obj directional move methods
    virtual void moveLeft() { obj->moveLeft(); this->updatePos(); }
    virtual void moveRight() { obj->moveRight(); this->updatePos(); }

    // direction obj is facing, getters and setters
    virtual void faceRight() { obj->faceRight(); }
    virtual void faceLeft() { obj->faceLeft(); }
    virtual bool facingRight() { return obj->facingRight(); }
    virtual bool facingLeft() { return obj->facingLeft(); }

    virtual QPoint getPos() { return obj->getPos(); }
    virtual void setPos(QPoint pos);
    virtual void setY(int y) { obj->setY(y); this->updatePos(); }
    virtual void setX(int x) { obj->setX(x); this->updatePos(); }

    virtual QPixmap *pix() { return img; }
    Entity *object() { return obj; }

    virtual ~MovableLabel();

private slots:
    //void keyPressEvent(QEvent *event){ qDebug() << "test" << endl; }

signals:
    void keyPressed();

};

#endif // MOVABLELABEL_H
