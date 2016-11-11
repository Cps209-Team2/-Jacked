#include <QPixmap>
#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPoint>
#include <QPaintEvent>
#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "weapon.h"
#include "entity.h"
#include "movablelabel.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "QString"
#include "world.h"
#include "collision.h"
#include "playerlabel.h"
#include "enemylabel.h"

namespace constants
{
    int gravity = 1;
}

gameWidget::gameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameWidget)
{
    this->setParent(parent);
    ui->setupUi(this);

    //timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(frame()));
    timer->setInterval(33);
    timer->start();

    //world->loadFile(QString::fromLocal8Bit(":/Levels/lvl1"));

    //test player
    qDebug() << "creating player" << endl;
    player = new Player(0,600,new Weapon(QString::fromLocal8Bit("fist")));
    lbl = new PlayerLabel(this,player, new QPixmap(":/Images/Images/player_idle_right.png"));
    lbl->updatePos();

    qDebug() << "created player" << endl;

    //test enemy
    qDebug() << "creating enemies" << endl;
    enemy = new Enemy(600,600,new Weapon(QString::fromLocal8Bit("fist")), player);
    //World::addEnemy(enemy);
    qDebug() << "created enemies" << endl;
    elbl = new MovableLabel(this,enemy, new QPixmap(":/Images/Images/enemy_left (1).png"));
    elbl->show();
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
    enemyPixChange = 0;
    hitCount = 0;

    start = dynamic_cast<StartWindow *>(parent)->getStart();
}

void gameWidget::begin() {
    //for (int i = 0; i < World::instance()->getEnemies().size(); ++i) {
    //World::instance()->getEnemies().at(i)->beginGame();
    //}
    enemy->beginGame();
}



void gameWidget::frame()
{

    if(lbl->player()->getHP() == 0)
    {
        lbl->player()->setHP(-500);
        QMessageBox dieBox;
        dieBox.setText("Game Over!");
        dieBox.exec();
        lbl->player()->setBody(new QRect());
        this->hide();
        start->show();
        start->setFocus();
    }

    if(lbl->player()->getPos().y() == 0)
    {
        isGrounded = true;
    }

    if(lbl->player() != NULL)
        this->playerMove();
    if(elbl->object() != NULL)
    {
        this->enemyMove();
        this->collide();
        this->lblUpdate();
    }

}

void gameWidget::playerMove()
{
    if(lbl->player()->getPos().x() < 0)
    {
        lbl->getPos().setX(0);
        lbl->updatePos();
    }
    else if(lbl->player()->getPos().x() > 964)
    {
        lbl->getPos().setX(964);
        lbl->updatePos();
    }
    if(lbl->player()->isCrouching())
    {

    }
    else if(lbl->player()->isAttacking())
    {

    }
    else
    {
        if(movLeft && lbl->player()->getPos().x() > 0)
        {
            lbl->moveLeft();
        }
        else if(movRight && lbl->player()->getPos().x() < 964)
        {
            lbl->moveRight();
        }
        if(jump)
        {
            jump = lbl->player()->jump();
        }
    }
}

void gameWidget::enemyMove()
{
    enemy->move();
}

void gameWidget::collide()
{
    Collision *bounce = new Collision(this->lbl->player(),this->elbl->object());
    CollisionInfo *data(bounce->getData());
    if(data->collide())
    {
        Entity *temp1 = data->getObj1();
        Entity *temp2 = data->getObj2();
        if(lbl->player()->isCrouching())
        {
        }
        else
        {
            if(!dynamic_cast<Player *>(temp1)->isAttacking())
            {
                //qDebug() << "collide" << endl;
                if(temp1->isPlayer())
                {
                    if(!dynamic_cast<Player *>(temp1)->isCrouching())
                    {
                        if(temp2->facingRight())
                        {
                            temp1->setX(temp1->getPos().x() + data->getX() + 130);
                            temp1->setY(temp1->getPos().y() - data->getY());
                        }
                        else
                        {
                            temp1->setX(temp1->getPos().x() + data->getX() - 130);
                            temp1->setY(temp1->getPos().y() - data->getY());
                        }
                        temp1->takeDmg(temp2->getDmg());
                    }
                    dynamic_cast<Player *>(temp1)->setHit(true);
                    hitCount = 0;
                }
            }
            else
            {
                if(temp2->facingRight())
                {
                    temp2->setX(temp2->getPos().x() - data->getX() - 130);
                    temp2->setY(temp2->getPos().y() - data->getY());
                }
                else
                {
                    temp2->setX(temp2->getPos().x() - data->getX() + 130);
                    temp2->setY(temp2->getPos().y() - data->getY());
                }
                temp2->takeDmg(10);
                if(temp2->getHP() <= 0)
                {
                    elbl->hide();
                    //elbl->object()->setBody(nullptr);
                    //delete elbl->object();
                }
            }
        }
    }
}

void gameWidget::lblUpdate()
{
    if(hitCount == 13)
    {
        lbl->player()->setHit(false);
    }
    else if(lbl->player()->isHit())
    {
        if(lbl->player()->facingRight())
            lbl->updateImg(new QPixmap(":/Images/Images/player_hit_right.png"));
        else
            lbl->updateImg(new QPixmap(":/Images/Images/player_hit_left.png"));
    }
    else if(lbl->player()->isCrouching())
    {
        if(lbl->player()->facingLeft())
            lbl->updateImg(new QPixmap(":/Images/Images/player_crouch_left.png"));
        else
            lbl->updateImg(new QPixmap(":/Images/Images/player_crouch_right.png"));
    }
    else if(lbl->player()->isAttacking())
    {
        if(lbl->player()->facingRight())
            lbl->updateImg(new QPixmap(":/Images/Images/player_attack_right (1).png"));
        else
            lbl->updateImg(new QPixmap(":/Images/Images/player_attack_left (1).png"));
    }
    else
    {
        if(jump && !lbl->player()->isAttacking())
        {
            if(lbl->facingRight())
            {
                if(lbl->player()->rise())
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_jump_right (rise).png"));
                } else {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_jump_right (fall).png"));
                }
            }
            else if(lbl->facingLeft())
            {
                if(lbl->player()->rise())
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_jump_left (rise).png"));
                } else {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_jump_left (fall).png"));
                }
            }
        }
        else
        {
            // standing still
            if(!movLeft && !movRight && lbl->facingRight() && !lbl->player()->rise())
            {
                lbl->updateImg(new QPixmap(":/Images/Images/player_idle_right.png"));
            }
            else if(!movLeft && !movRight && lbl->facingLeft() && !lbl->player()->rise())
            {
                lbl->updateImg(new QPixmap(":/Images/Images/player_idle_left.png"));
            }

            //walking
            else if(movLeft && !lbl->player()->rise())
            {
                if(pixChange == 0)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_left (1).png"));
                }
                else if(pixChange == 4)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_left (2).png"));
                }
                else if(pixChange == 9)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_left (3).png"));
                }
                else if(pixChange == 14)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_left (4).png"));
                }
                else if(pixChange == 19)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_left (5).png"));
                }
                else if(pixChange == 24)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_left (6).png"));
                    pixChange = -1;
                }

                pixChange++;
            }
            else if(movRight && !lbl->player()->rise())
            {
                if(pixChange == 0)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_right (1).png"));
                }
                else if(pixChange == 4)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_right (2).png"));
                }
                else if(pixChange == 9)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_right (3).png"));
                }
                else if(pixChange == 14)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_right (4).png"));
                }
                else if(pixChange == 19)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_right (5).png"));
                }
                else if(pixChange == 24)
                {
                    lbl->updateImg(new QPixmap(":/Images/Images/player_run_right (6).png"));
                    pixChange = -1;
                }

                pixChange++;
            }

        }
    }


    //enemy
    if(elbl->facingLeft())
    {
        if(enemyPixChange == 0)
        {
            elbl->updateImg(new QPixmap(":/Images/Images/enemy_left (1).png"));
        }
        else if(enemyPixChange == 8)
        {
            elbl->updateImg(new QPixmap(":/Images/Images/enemy_left (2).png"));
        }
        else if(enemyPixChange == 16)
        {
            elbl->updateImg(new QPixmap(":/Images/Images/enemy_left (1).png"));
            enemyPixChange = -1;
        }

    }
    else if(elbl->facingRight())
    {
        if(enemyPixChange == 0)
        {
            elbl->updateImg(new QPixmap(":/Images/Images/enemy_right (1).png"));
        }
        else if(enemyPixChange == 8)
        {
            elbl->updateImg(new QPixmap(":/Images/Images/enemy_right (2).png"));
        }
        else if(enemyPixChange == 16)
        {
            elbl->updateImg(new QPixmap(":/Images/Images/enemy_right (1).png"));
            enemyPixChange = -1;
        }
    }

    enemyPixChange++;
    hitCount++;
    lbl->updatePos();
    elbl->updatePos();

    this->ui->lbScore->setText("Score: " + QString::number(player->getScore()));
    this->ui->lbHealth->setText("Health: " + player->showHealth());
}

void gameWidget::keyPressEvent(QKeyEvent *event)
{
    if(!lbl->player()->isHit())
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
            isGrounded = false;
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
            qDebug() << "atk" << endl;
            lbl->player()->setAttack(true);
        }
        else if(event->key() == Qt::Key_Down)
        {
                lbl->player()->crouch();
        }
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
        qDebug() << "release atk" << endl;
        lbl->player()->setAttack(false);
    }
    else if(event->key() == Qt::Key_Down)
    {
        lbl->player()->stand();
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
