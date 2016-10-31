#include <QPixmap>
#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "weapon.h"
#include "entity.h"
#include "movablelabel.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "QString"
#include "map.h"
#include "collision.h"

namespace constants
{
    int gravity = 4;
}

gameWidget::gameWidget(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::gameWidget)
{
    this->setParent(parent);
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(frame()));
    timer->setInterval(40);
    timer->start();
    world->loadFile(QString::fromLocal8Bit(":/Levels/lvl1"));

    for (int i = 0; i < world->getEnemies().size(); ++i)
    {
        elbl = new MovableLabel(this, world->getEnemies().at(i));
        QPixmap img(":/Images/tempEnemy.png");
        elbl->setPixmap(img.scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
        elbl->updatePos();
        elbls.push_back(elbl);
    }



    player = new Player(0,600,new Weapon(QString::fromLocal8Bit("fist")));
    lbl = new MovableLabel(this,player);
    QPixmap pix(":/Images/tempPlayer.png");
    lbl->setPixmap(pix.scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
    lbl->updatePos();

    enemy = new Enemy(400,600,new Weapon(QString::fromLocal8Bit("fist")));

    this->movLeft = false;
    this->movRight = false;
    this->jump = false;
}

void gameWidget::frame()
{
    this->move();
    for(auto i : world->getEnemies())
    {
        Collision check(world->_Player(), i);
        world->_Player()->setX(world->getPlayer().getPos().x() + check.checkCollision());
    }
}

void gameWidget::move()
{
    if(movLeft)
    {
        player->moveLeft();
    }
    else if(movRight)
    {
        player->moveRight();
    }

    lbl->updatePos();
}

void gameWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(player->getPos().x() >= 20)
        {
            this->movLeft = true;
            /*
            player->moveLeft();
            lbl->updatePos();
            enemy->moveRight();
            elbl->updatePos();
            */
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(player->getPos().x() <= 1004)
        {
            this->movRight = true;
            /*
            player->moveRight();
            lbl->updatePos();
            enemy->moveLeft();
            elbl->updatePos();
            */
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        player->getWeapon()->execute();
    }
    else if(event->key() == Qt::Key_Up)
    {
        jump = true;
    }
}

void gameWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        this->movLeft = false;
    }
    else if(event->key() == Qt::Key_Right)
    {
        this->movRight = false;
    }
    else if(event->key() == Qt::Key_Up)
    {
        jump = true;
    }
}

gameWidget::~gameWidget()
{
    timer->stop();
    delete ui;
}
