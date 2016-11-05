#ifndef PLAYERLABEL_H
#define PLAYERLABEL_H
#include <QPixmap>
#include "movablelabel.h"
#include "player.h"
#include "enemy.h"

class EnemyLabel: public MovableLabel
{
    Enemy *obj;
public:
    EnemyLabel(QWidget *parent, Entity *object, QPixmap *pix): MovableLabel(parent, object, pix)
    {
        obj = dynamic_cast<Enemy *>(object);
    }
    Enemy *player() { return obj; }

/*
    void setImg(QPixmap *pix)
    {
        img = pix;
    }
*/
    ~EnemyLabel();
};

#endif // PLAYERLABEL_H
