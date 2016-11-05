#include <QPixmap>
#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
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
#include "playerlabel.h"

namespace constants
{
    int gravity = 1;
}

gameWidget::gameWidget(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::gameWidget)
{
    this->setParent(parent);
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(frame()));
    timer->setInterval(30);
    timer->start();

    //testing if loadfile works
    world->loadFile(QString::fromLocal8Bit(":/Levels/lvl1"));

    //test player
    qDebug() << "creating player" << endl;
    player = new Player(0,600,new Weapon(QString::fromLocal8Bit("fist")));
    lbl = new PlayerLabel(this,player, new QPixmap(":/Images/Images/Player_RIGHT (8).png"));
    lbl->updatePos();

    qDebug() << "created player" << endl;

    //test enemy
    qDebug() << "creating enemies" << endl;
    enemy = new Enemy(600,600,new Weapon(QString::fromLocal8Bit("fist")), player);
    qDebug() << "created enemies" << endl;
    elbl = new MovableLabel(this,enemy, new QPixmap(":/Images/robot.png"));
    elbl->updatePos();

    qDebug() << "created elbl" << endl;

    //direction bools
    this->movLeft = false;
    this->movRight = false;

    //jumping and falling bools
    this->jump = false;
    this->falling = false;
    this->isGrounded = false;
    pixChange = 0;
}

void gameWidget::frame()
{

    if(lbl->player()->getHP() == 0)
    {
        QMessageBox dieBox;
        dieBox.setText("Game Over!");
        dieBox.exec();
        delete this;
    }

    Collision bounce(this->player,this->enemy);
    player->setX(player->getPos().x() + bounce.checkCollision());

    this->playerMove();
    this->lblUpdate();

}

void gameWidget::playerMove()
{
    if(movLeft)
    {
        lbl->moveLeft();
    }
    else if(movRight)
    {
        lbl->moveRight();
    }
    if(jump)
    {
        jump = lbl->player()->jump();
        lbl->updatePos();
    }
    //lbl->updatePos();
/*
    if(!falling && !isGrounded)
    {
        player->jump();
    }

    if(lbl->getPos().y() > 0)
    {
        falling = true;
    }
    else if(lbl->getPos().y() < 0)
    {
        lbl->setY(0);
        falling = false;
    }
    if(falling)
    {
        lbl->setY(lbl->getPos().y() + constants::gravity);
        //player->getPos().setY(player->getPos().y() + constants::gravity);
        ++constants::gravity;
    }
*/
}

void gameWidget::enemyMove()
{
    enemy->move();
    elbl->updatePos();
}

void gameWidget::lblUpdate()
{

    // standing still
    if(!movLeft && !movRight && lbl->facingRight())
    {
        lbl->updateImg(new QPixmap(":/Images/Images/Player_RIGHT (8).png"));
    }
    else if(!movLeft && !movRight && lbl->facingLeft())
    {
        lbl->updateImg(new QPixmap(":/Images/Images/Player_LEFT (8).png"));
    }

    //walking
    else if(movLeft)
    {
        pixChange++;

        if(pixChange == 0)
        {
            lbl->updateImg(new QPixmap(":/Images/Images/Player_LEFT (2).png"));
        }
        else if(pixChange == 16)
        {
            lbl->updateImg(new QPixmap(":/Images/Images/Player_LEFT (6).png"));
        }
        else if(pixChange == 32)
        {
            lbl->updateImg(new QPixmap(":/Images/Images/Player_LEFT (2).png"));
            pixChange = -1;
        }
    }
    else if(movRight)
    {
        pixChange++;

        if(pixChange == 0)
        {
            lbl->updateImg(new QPixmap(":/Images/Images/Player_RIGHT (6).png"));
        }
        else if(pixChange == 16)
        {
            qDebug() << "1" << endl;
            lbl->updateImg(new QPixmap(":/Images/Images/Player_RIGHT (6).png"));
        }
        else if(pixChange == 32)
        {
            qDebug() << "2" << endl;
            lbl->updateImg(new QPixmap(":/Images/Images/Player_RIGHT (2).png"));
            pixChange = -1;
        }
    }
}

void gameWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        this->movLeft = true;
        this->movRight = false;
    }
    else if(event->key() == Qt::Key_Right)
    {
        this->movRight = true;
        this->movLeft = false;
    }
    else if(event->key() == Qt::Key_Up)
    {
        jump = true;
        //lbl->setY(lbl->getPos().y() - 200);
        //falling = true;
        //isGrounded = false;

    /*
        player->getWeapon()->execute();
        if(player->getPos().x() > 350)
        {
            player->setX(50);
        }
        else
        {
            player->setX((650));
        }
    */
    }
    else if(event->key() == Qt::Key_Space)
    {
        hit = true;
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

    }
    else if(event->key() == Qt::Key_Space)
    {
        hit = false;
    }
}

gameWidget::~gameWidget()
{
    timer->stop();
    delete timer;
    delete ui;
    delete world;
    delete player;
    delete enemy;
    lbl->deleteLater();
    elbl->deleteLater();
}
