#include "enemy.h"
#include "entity.h"
#include <vector>

int Enemy::nextId = 0;

Enemy::Enemy(int x, int y, Weapon *item, Player *obj, int ms):Entity(x, y)
{
    // hitbox (QRect)
    body = new QRect(pos.x(),pos.y(),80,80);

    // assigning an object reference for move function
    player = obj;

    // assign weapon, which determines how much damage the enemy does.  HP determines how much damage the entity can take
    weapon = item;

    HP = 15;

    hit = false;
    hitCount = 0;

    // enemy always faces toward player on spawn
    if(player->getPos().x() < this->pos.x())
    {
        this->faceLeft();
    }
    else
    {
        this->faceRight();
    }

    // random movespeed between 1 and 6 pixels per frame
    moveSpeed = ms;

    // used to give each enemy a unique ID
    int id = ++nextId;

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

// Saves the enemy state to the file "World.jkd"
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

// +500 points!
Enemy::~Enemy()
{
    player->addScore(500);
    delete weapon;
}
