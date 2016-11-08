
#include "enemy.h"

Enemy::Enemy(int x, int y, Weapon *item, Player *obj)
{
    pos.setX(x);
    pos.setY(y);
    qDebug() << "set position" << endl;
    weapon = item;
    body = new QRect(pos.x(),pos.y(),80,80);
    player = obj;
    qDebug() << "assigned player reference" << endl;
    this->start = false;
    qDebug() <<  "assigned body and player obj" << endl;
    if(item->getType() == QString::fromLocal8Bit("fist"))
    { DMG = 5; }
    else
    { DMG = 10; }

    HP = 30;
    qDebug() << "assigned player HP" << endl;
    if(player->getPos().x() < this->pos.x())
    {
        this->faceLeft();
    }
    else
    {
        this->faceRight();
    }
    //World::instance()->addEnemy(this);
}

void Enemy::move()
{
    if(player == NULL)
    {

    }
    if(this->start == true)
    {
        if(player->isCrouching())
        {
            if(this->facingLeft())
                this->moveLeft();
            else
                this->moveRight();
        }
        else
        {
            if(player->getPos().x() < pos.x())
            {
                this->moveLeft();
            }
            else
            {
                this->moveRight();
            }
        }

        if(this->getPos().x() < 0)
        {
            this->moveRight();
        }
        else if(this->getPos().x() > 964)
        {
            this->moveLeft();
        }
    }
}

void Enemy::moveLeft()
{
    pos.setX(pos.x() - 2);
    this->faceLeft();
}

void Enemy::moveRight()
{
    pos.setX(pos.x() + 2);
    this->faceRight();
}

void Enemy::saveState(QFile *file)
{
    QTextStream save(file);
    save << "position:" << pos.x() << "," << pos.y() << endl;
    save << "weapon:" << getWeapon()->getType() << "\n\n";
}

Enemy::~Enemy()
{
    player->setScore(500);
}
