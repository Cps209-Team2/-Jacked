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
#include <QMessageBox>

namespace constants
{
    int gravity = 3;
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

    /*
    for(int i = 0;i < world->getEnemies().size();i++)
    {
        elbls.push_back(new MovableLabel(this, world->getEnemies().at(i)));
    }

    for (unsigned i = 0; i < world->getEnemies().size(); ++i)
    {
        qDebug() << "creating enemy label..." << endl;
        elbl = new MovableLabel(this, world->getEnemies().at(i));
        qDebug() << "created label" << endl;
        QPixmap img(":/Images/robot.png");
        elbl->setPixmap(img.scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
        elbl->updatePos();
        qDebug() << "created enemy" << endl;
        elbls.push_back(elbl);
        qDebug() << "stored enemy" << endl;

    }
    //*/


    qDebug() << "creating player" << endl;
    player = new Player(0,600,new Weapon(QString::fromLocal8Bit("fist")));
    lbl = new MovableLabel(this,player);
    QPixmap pix(":/Images/tempPlayer.png");
    lbl->setPixmap(pix.scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
    lbl->updatePos();
    qDebug() << "created player" << endl;

    qDebug() << "creating enemies" << endl;
    enemy = new Enemy(600,600,new Weapon(QString::fromLocal8Bit("fist")), player);
    qDebug() << "created enemies" << endl;
    elbl = new MovableLabel(this,enemy);
    QPixmap epix(":/Images/robot.png");
    elbl->setPixmap(epix.scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
    elbl->updatePos();
    qDebug() << "created elbl" << endl;

    this->movLeft = false;
    this->movRight = false;
    this->jump = false;
}

void gameWidget::frame()
{
    if(player->getHP() == 0)
    {
        QMessageBox dieBox;
        dieBox.setText("Game Over!");
        dieBox.exec();
        delete this;
    }
    if(player->getPos().y() == 0)
    { isGrounded = true; }

    this->playerMove();
    this->enemyMove();

    /*
    if(movLeft && hit && (enemy->getPos().x() - player->getPos().x() < 30))
    {
        enemy->takeDmg(player->getDmg());
        qDebug() << "take that!" << endl;
    }

    else if(movRight && hit && (player->getPos().x() - enemy->getPos().x() < 30))
    {
        enemy->takeDmg((player->getDmg()));
        qDebug() << "take that!" << endl;
    }
    */

    Collision bounce(this->player,this->enemy);

    player->setX(player->getPos().x() + bounce.checkCollision());
    //enemy->setX(enemy->getPos().x() + bounce.checkCollision());

    /*
    for(auto i : world->getEnemies())
    {
        Collision check(world->_Player(), i);
        world->_Player()->setX(world->getPlayer().getPos().x() + check.checkCollision());
    }
    for(Enemy *i : world->getEnemies())
    {
        i->move();
    }*/
}

void gameWidget::playerMove()
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

    if(jump)
    {
        player->jump();
    }
}

void gameWidget::enemyMove()
{
    enemy->move();
    elbl->updatePos();
}

void gameWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(player->getPos().x() >= 20)
        {
            this->movLeft = true;
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(player->getPos().x() <= 1004)
        {
            this->movRight = true;
        }
    }
    else if(event->key() == Qt::Key_Up)
    {
        player->getWeapon()->execute();
        if(player->getPos().x() > 350)
        {
            player->setX(50);
        }
        else
        {
            player->setX((650));
        }
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
