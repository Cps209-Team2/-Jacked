#include "playerlabel.h"

void PlayerLabel::updateImg(QPixmap *pix)
{
    img = pix;

        if(obj->isCrouching())
            this->setPixmap(pix->scaled(QSize(64,64),Qt::IgnoreAspectRatio, Qt::FastTransformation));
        else if(obj->isAttacking())
            this->setPixmap(pix->scaled(QSize(75,81),Qt::IgnoreAspectRatio, Qt::FastTransformation));
        else
            this->setPixmap(pix->scaled(QSize(68,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

PlayerLabel::~PlayerLabel()
{
    delete obj;
}
