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

protected:
    Q_OBJECT

    QPixmap *img;
    Entity *obj;

public:
    explicit MovableLabel(QWidget* parent, Entity* object, QPixmap* pix): QLabel(parent), obj(object), img(pix)
    {
        this->setPixmap(pix->scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
    }
    void updatePos() { this->move(obj->getPos()); }
    void updateImg(QPixmap*);

    void moveLeft() { obj->moveLeft(); this->updatePos(); }
    void moveRight() { obj->moveRight(); this->updatePos(); }

    QPoint getPos() { return obj->getPos(); }
    void setPos(QPoint pos);
    void setY(int y) { obj->setY(y); this->updatePos(); }
    void setX(int x) { obj->setX(x); this->updatePos(); }

    QPixmap *pix() { return img; }
    Entity *object() { return obj; }

    virtual ~MovableLabel();

private slots:
    //void keyPressEvent(QEvent *event){ qDebug() << "test" << endl; }

signals:
    void keyPressed();

};

#endif // MOVABLELABEL_H
