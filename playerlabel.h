#ifndef PLAYERLABEL_H
#define PLAYERLABEL_H
#include <QPixmap>
#include "movablelabel.h"
#include "player.h"

// simply used for clarity to distinguish player MovableLabel from enemy MovableLabels
class PlayerLabel: public MovableLabel
{
    Player *obj;
public:
    PlayerLabel(QWidget *parent, Entity *object, QPixmap *pix): MovableLabel(parent, object, pix)
    {
        obj = dynamic_cast<Player *>(object);
    }
    Player *player() { return obj; }
    void updateImg(QPixmap *pix);

    ~PlayerLabel();
};

#endif // PLAYERLABEL_H
