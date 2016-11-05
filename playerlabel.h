#ifndef PLAYERLABEL_H
#define PLAYERLABEL_H
#include <QPixmap>
#include "movablelabel.h"
#include "player.h"

class PlayerLabel: public MovableLabel
{
    Player *obj;
public:
    PlayerLabel(QWidget *parent, Entity *object, QPixmap *pix): MovableLabel(parent, object, pix)
    {
        obj = dynamic_cast<Player *>(object);
    }
    Player *player() { return obj; }

/*
    void setImg(QPixmap *pix)
    {
        img = pix;
    }
*/
    ~PlayerLabel();
};

#endif // PLAYERLABEL_H
