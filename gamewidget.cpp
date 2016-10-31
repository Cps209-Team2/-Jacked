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

namespace constants
{
    int gravity = 4;
}

gameWidget::gameWidget(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::gameWidget)
{
    timerTest = 0;
    this->setParent(parent);
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(frame()));
    timer->setInterval(40);
    timer->start();

    player = new Player(0,600,new Weapon(QString::fromLocal8Bit("fist")));
    lbl = new MovableLabel(this,player);
    QPixmap pix(":/Images/tempPlayer.png");
    lbl->setPixmap(pix.scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
    lbl->updatePos();
    this->movLeft = false;
    this->movRight = false;
    this->jump = false;
}

void gameWidget::frame()
{
    this->move();
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
