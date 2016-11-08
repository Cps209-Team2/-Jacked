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
    body = new QRect(pos.x(),pos.y(),68,80);

    jumpSpeed = 24;
    jumpDuration = 0;
    HP = 30;

    attackDuration = 0;
    attacking = false;
    right = true;
    left = false;
    crouching = false;
    hit = false;

    if(item->getType() == QString::fromLocal8Bit("fist"))
    {
        //qDebug() << item->getType() << endl;
        DMG = 10;
    }
    else
    {
        //qDebug() << item->getType() << endl;
        DMG = 15;
    }
}

void Player::saveScore(QFile *file)
{
    QTextStream save(file);

    save << getName() << ":" << getScore() << endl;
    //TODO load the scores file into a vector and sort it by score
}

void Player::saveState(QFile *file)
{

    QTextStream save(file);
    save << "name:" << getName() << endl;
    save << "position:" << pos.x() << "," << pos.y() << endl;
    save << "weapon:" << getWeapon()->getType() << "\n\n";
}

void Player::moveLeft()
{
    pos.setX(pos.x() - 11);
    body->moveTo(pos);
    this->faceLeft();
}

void Player::moveRight()
{
    pos.setX(pos.x() + 11);
    body->moveTo(pos);
    this->faceRight();
}


// + and - seem backwards but are correct because y = 0 is at the top
bool Player::jump()
{
    if(jumpDuration <= 13)
    {
        _rise = true;
    }
    else
    {
        _rise = false;
    }
    if(jumpDuration < 25)
    {
    pos.setY(pos.y() - jumpSpeed);
        jumpSpeed -= 2;
        ++jumpDuration;
        return true;
    }
    else
    {
        jumpDuration = 0;
        jumpSpeed = 24;
        falling = false;
        return false;
    }

    return false;
}

void Player::recoil(CollisionInfo *)
{

}

bool Player::attack()
{
    if(!attacking || attackDuration > 24)
    {
        //body = new QRect(pos.x(),pos.y(),68,80);
        //attackDuration = -64;
        //attacking = false;
        //qDebug() << "no ATK" << endl;
        return false;
    }
    if(attacking)
    {
        //body = new QRect(pos.x(),pos.y(),68,300);

        //++attackDuration;
    }
    return true;

}

// Passes points to be ADDED to current score
void Player::setScore(double initScore) {
    score += initScore; //note += not =
}

//creates an image of health symbols for the health label.
QString Player::showHealth() {
    QString healthBar = "";
    if (this->getHP() > 0) {
        for (int i = 0; i < this->getHP(); i += 5) {
            healthBar += "&";
        }
        return healthBar;
    }
    else
        return "";
}

Player::~Player()
{
    delete this->weapon;
}
