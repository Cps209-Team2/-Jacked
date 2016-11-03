#include "player.h"
#include "entity.h"
#include <QRect>
#include "collision.h"
#include <QString>

Player::Player(int initx, int inity, Weapon *item)
{
    pos.setX(initx);
    pos.setY(inity);
    weapon = item;
    body = new QRect(pos.x(),pos.y(),80,80);

    jumpSpeed = 7;
    HP = 30;

    if(item->getType() == QString::fromLocal8Bit("fist"))
    {
        qDebug() << item->getType() << endl;
        DMG = 10;
    }
    else
    {
        qDebug() << item->getType() << endl;
        DMG = 15;
    }
}

void Player::saveScore(QFile *file)
{
    QTextStream save(file);

    save << getName() << ":" << getScore() << endl;
    //TODO load the scores file into a vector and sort it by score
}
/*
void Player::saveState(QFile *file)
{
    save << "position:" << pos.x() << "," << pos.y() << endl;
    save << "weapon:" << getWeapon() << "\n\n";
}
*/
void Player::moveLeft()
{
    pos.setX(pos.x() - 6);
    body->moveTo(pos);
}

void Player::moveRight()
{
    pos.setX(pos.x() + 6);
    body->moveTo(pos);
}


// + and - seem backwards but are correct because y = 0 is at the top
bool Player::jump()
{
    if(jumpSpeed > 0)
    {
        pos.setY(pos.y() - jumpSpeed);
        --jumpSpeed;
        return true;
    }
    else if(jumpSpeed == 0)
    {
        jumpSpeed = 7;
        return false;
    }
    return false;
}

void Player::fall(int y)
{
    pos.setY(pos.y() + y);
}

Player::~Player()
{
    delete this->weapon;
}
