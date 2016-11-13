#include "enemy.h"
#include "entity.h"
#include <vector>

int Enemy::nextId = 0;

Enemy::Enemy(int x, int y, Weapon *item, Player *obj, int ms)
{
    pos.setX(x);
    pos.setY(y);
    qDebug() << "set position" << endl;
    weapon = item;
    body = new QRect(pos.x(),pos.y(),80,80);
    player = obj;
    qDebug() << "assigned player reference" << endl;

    if(item->getType() == QString::fromLocal8Bit("fist"))
    { DMG = 5; }
    else
    { DMG = 10; }

    HP = 30;
    qDebug() << "assigned enemy HP" << endl;
    if(player->getPos().x() < this->pos.x())
    {
        this->faceLeft();
    }
    else
    {
        this->faceRight();
    }
    moveSpeed = ms;
    int id = ++nextId;
    //qDebug() << id << endl;
    //World::instance()->addEnemy(this);
}

void Enemy::move()
{
        if(player->isCrouching() || !player->isGrounded())
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

void Enemy::moveLeft()
{
    pos.setX(pos.x() - moveSpeed);
    this->faceLeft();
}

void Enemy::moveRight()
{
    pos.setX(pos.x() + moveSpeed);
    this->faceRight();
}

void Enemy::saveState(QFile *file)
{
    QTextStream save(file);
    std::vector<Enemy*> enemies = World::instance().getEnemies();
    Enemy *saveEnemy;
    save << "#Enemies" << endl;
    for (int i = 0; i < enemies.size(); ++i)
    {
        qDebug() << "Getting the enemy stored at" << i;
        saveEnemy = dynamic_cast<Enemy*>(enemies.at(i));
        qDebug() << "Writing that enemy to the file";
        save << "position:" << pos.x() << "," << pos.y() << endl;
        save << "weapon:" << getWeapon()->getType() << "\n\n";
    }
    save << "*";
}

Enemy::~Enemy()
{
    player->setScore(500);
}
