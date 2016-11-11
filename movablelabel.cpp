#include "movablelabel.h"
#include "player.h"

MovableLabel::MovableLabel(QWidget *parent, Entity *object, QPixmap *pix): QLabel(parent), obj(object), img(pix)
{
    if(obj->isPlayer())
        this->setPixmap(pix->scaled(QSize(68,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
    else
        this->setPixmap(pix->scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void MovableLabel::updateImg(QPixmap *pix)
{
    img = pix;

    if(obj->isPlayer())
        if(dynamic_cast<Player *>(obj)->isCrouching())
            this->setPixmap(pix->scaled(QSize(64,64),Qt::IgnoreAspectRatio, Qt::FastTransformation));
        else
            this->setPixmap(pix->scaled(QSize(68,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
    else
        this->setPixmap(pix->scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void MovableLabel::setPos(QPoint pos)
{
    obj->setX(pos.x());
    obj->setY(pos.y());
    this->updatePos();

}

MovableLabel::~MovableLabel()
{

}
