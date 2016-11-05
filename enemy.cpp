#include <QString>
#include <QDebug>
#include "enemy.h"

Enemy::Enemy(int x, int y, Weapon *item, Player *obj)
{
    pos.setX(x);
    pos.setY(y);
    weapon = item;
    body = new QRect(pos.x(),pos.y(),80,80);
    player = obj;
    if(item->getType() == QString::fromLocal8Bit("fist"))
    { DMG = 5; qDebug() << item << endl; }
    else
    { DMG = 10; qDebug() << item << endl;}

    left = true;
    right = false;
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
