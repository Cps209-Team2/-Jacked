#ifndef PLAYERLABEL_H
#define PLAYERLABEL_H
#include <QPixmap>
#include "movablelabel.h"

class PlayerLabel: public MovableLabel
{
public:
    PlayerLabel(QWidget *parent, Entity *obj, QPixmap *pix): MovableLabel(parent, obj, pix)
    {

    }
/*
    void setImg(QPixmap *pix)
    {
        img = pix;
    }
*/
    ~PlayerLabel();
};

#endif // PLAYERLABEL_H
