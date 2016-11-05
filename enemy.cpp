#include <QString>
#include <QDebug>
#include "enemy.h"

Enemy::Enemy(int x, int y, Weapon *item, Player *obj)
{
    pos.setX(x);
    pos.setY(y);
    qDebug() << "set position" << endl;
    weapon = item;
    body = new QRect(pos.x(),pos.y(),80,80);
    player = obj;
    qDebug() <<  "assigned body and player obj" << endl;
    if(item->getType() == QString::fromLocal8Bit("fist"))
    { DMG = 5; }
    else
    { DMG = 10; }

    if(player->getPos().x() < this->pos.x())
    {
        this->faceLeft();
    }
    else
    {
        this->faceRight();
    }
}

void Enemy::move()
{
    if(player == NULL)
    {

    }
    else if(player->getPos().x() < pos.x())
    {
        this->moveLeft();
        left = true;
    }
    else
    {
        this->moveRight();
        right = true;
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

Enemy::~Enemy()
{

}
