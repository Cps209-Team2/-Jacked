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
#include "save.h"
#include "escmenu.h"

#include <vector>

namespace constants
{
    int gravity = 1;
}

gameWidget::gameWidget(QWidget *parent) : QWidget(parent), ui(new Ui::gameWidget) // gameWidget Constuctor
{
    this->setParent(parent);
    ui->setupUi(this);
    world = World::instance();
    this->loadTestLvl();
    this->spawnPlayer();


    //player = world->_Player();

    //timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(frame()));
    timer->setInterval(33);
    timer->start();

    //jumping and falling bools
    this->jump = false;
    pixChange = 0;
    enemyPixChange = 0;
    hitCount = 0;
    isOpen = true;
    start = dynamic_cast<StartWindow *>(parent)->getStart();
}

void gameWidget::spawnPlayer()
{
    qDebug() << "creating player" << endl;
    //player = new Player(0,600,new Weapon("fist"));
    player = world._Player();
    //world.addEntity(player);
    lbl = new PlayerLabel(this,player, new QPixmap(":/Images/Images/player_idle_right.png"));
    lbl->updatePos();
}

void gameWidget::loadTestLvl()
{

    world.loadFile(":/Levels/lvl1");
    std::vector<Enemy*> enemies = world.getEnemies();

    for(int i = 0; i < world.getEnemies().size(); i++)
    {
        MovableLabel *lbl = new MovableLabel(this, enemies.at(i), new QPixmap(":/Images/Images/enemy_left (1).png"));
        elbls.push_back(lbl);
        world.getEnemies().at(i)->setLabel(lbl);
    }
}

void gameWidget::frame()
{
    qDebug() << elbls.size() << endl;

    if(lbl->player()->getHP() == 0)
    {
        player->setHP(-500);
        QMessageBox dieBox;
        dieBox.setText("Game Over!");
        dieBox.exec();
        this->hide();
        this->reset();
        timer->stop();
        start->show();
        start->setFocus();
    }

    if(lbl->player()->getPos().y() == 0)
    {
        player->setGrounded(true);
    }

    if(world.getEnemies().size() == 0 && isOpen == true)
    {
        QMessageBox winBox;
        winBox.setText("You Win!");
        winBox.exec();
        this->hide();
        this->reset();
        start->show();
        start->setFocus();
        timer->stop();
        isOpen = false;
    }
    for(int i = 0; i < world.getEnemies().size(); i++)
    {
        //MovableLabel *temp = elbls.at(i);

        this->enemyMove(dynamic_cast<Enemy*>(world.getEnemies().at(i)));
        Collision bounce(player,world.getEnemies().at(i));
        CollisionInfo *data = bounce.getData();
        this->collide(data);
    }
    this->elblUpdate();
    this->playerMove();
    this->lblUpdate();

}
void gameWidget::updatePlayerCondition()
{

}

void gameWidget::playerMove()
{
    if(player->getPos().x() < 0)
    {
        player->setX(0);
        lbl->updatePos();
    }
    else if(player->getPos().x() > 964)
    {
        player->setX(964);
        lbl->updatePos();
    }
    if(lbl->player()->isCrouching()){ }

    else if(lbl->player()->isAttacking()){ }

    if(player->movingLeft() && !player->movingRight() && lbl->player()->getPos().x() > 0)
    {
        lbl->moveLeft();
    }
    else if(player->movingRight() && !player->movingLeft() && lbl->player()->getPos().x() < 964)
    {
        lbl->moveRight();
    }
    if(jump)
    {
        jump = lbl->player()->jump();
    }
}

void gameWidget::enemyMove(Enemy *obj)
{
    obj->move();
}

void gameWidget::collide(CollisionInfo *data)
{
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
                player->setAttack(false);
                temp2->takeDmg(10);
                if(temp2->getHP() <= 0)
                {
                    temp2->hideLabel();
                    for(MovableLabel *i : elbls)
                    {
                        if(i->isHidden())
                        {
                            i->hide();
                        }
                    }
                    world.trash(temp2->getId());
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
            if(!player->movingLeft() && !player->movingRight() && lbl->facingRight() && !lbl->player()->rise())
            {
                lbl->updateImg(new QPixmap(":/Images/Images/player_idle_right.png"));
            }
            else if(!player->movingLeft() && !player->movingRight() && lbl->facingLeft() && !lbl->player()->rise())
            {
                lbl->updateImg(new QPixmap(":/Images/Images/player_idle_left.png"));
            }

            //walking
            else if(player->movingLeft() && !player->rise())
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
            else if(player->movingRight() && !player->rise())
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

    hitCount++;
    lbl->updatePos();


    this->ui->lbScore->setText("Score: " + QString::number(player->getScore()));
    this->ui->lbHealth->setText("Health: " + player->showHealth());
}

void gameWidget::elblUpdate()
{
    for(MovableLabel *i : elbls)
    {
        if(i)
        {
            if(enemyPixChange == 0)
            {
                i->updateImg(new QPixmap(":/Images/Images/enemy_left (1).png"));
            }
            else if(enemyPixChange == 8)
            {
                i->updateImg(new QPixmap(":/Images/Images/enemy_left (2).png"));
            }
            else if(enemyPixChange == 16)
            {
                i->updateImg(new QPixmap(":/Images/Images/enemy_left (1).png"));
                enemyPixChange = -1;
            }

        }
        else if(i->facingRight())
        {
            if(enemyPixChange == 0)
            {
                i->updateImg(new QPixmap(":/Images/Images/enemy_right (1).png"));
            }
            else if(enemyPixChange == 8)
            {
                i->updateImg(new QPixmap(":/Images/Images/enemy_right (2).png"));
            }
            else if(enemyPixChange == 16)
            {
                i->updateImg(new QPixmap(":/Images/Images/enemy_right (1).png"));
                enemyPixChange = -1;
            }
        }
        i->updatePos();
    }
    enemyPixChange++;
}

void gameWidget::keyPressEvent(QKeyEvent *event)
{
    if(!lbl->player()->isHit())
    {
        if(event->key() == Qt::Key_Left)
        {
            player->turnLeft();
        }
        else if(event->key() == Qt::Key_Right)
        {
            player->turnRight();
        }
        if(event->key() == Qt::Key_Up)
        {
            jump = true;
            player->setGrounded(false);
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
        if(event->key() == Qt::Key_Space)
        {
            lbl->player()->setAttack(true);
        }
        if(event->key() == Qt::Key_Down)
        {
            lbl->player()->crouch();
        }
        if(event->key() == Qt::Key_Escape)
        {
            timer->stop();
            escMenu = new EscMenu(this);
            escMenu->show();
        }
    }
}

void gameWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left && !player->movingRight())
    {
        player->stopMoving();
    }
    else if(event->key() == Qt::Key_Right && !player->movingLeft())
    {
        player->stopMoving();
    }
    else if(event->key() == Qt::Key_Space)
    {
        player->setAttack(false);
    }
    else if(event->key() == Qt::Key_Down)
    {
        player->stand();
    }
}

void gameWidget::reset()
{
    for(Enemy *i : world.getEnemies())
    {
        world.trash(i->getId());
    }
    for(MovableLabel *i : elbls)
    {
        i->deleteLater();
    }
}

gameWidget::~gameWidget()
{
    timer->stop();
    delete timer;
    delete ui;
    //delete world;
}
