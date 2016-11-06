#include "movablelabel.h"



void MovableLabel::updateImg(QPixmap *pix)
{
    img = pix;

    if(obj->isPlayer())
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
    delete img;
    delete obj;
}
