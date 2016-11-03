#include "movablelabel.h"



void MovableLabel::updateImg(QPixmap *pix)
{
    img = pix;
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
