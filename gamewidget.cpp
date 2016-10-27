#include <QPixmap>
#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include "gamewidget.h"
#include "ui_gamewidget.h"
#include "weapon.h"
#include "entity.h"
#include "movablelabel.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "QString"

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

    player = new Player(0,700,new Weapon(QString::fromLocal8Bit("fist")));
    lbl = new MovableLabel(this,player);
    QPixmap pix(":/Images/tempPlayer.png");
    lbl->setPixmap(pix.scaled(QSize(80,80),Qt::IgnoreAspectRatio, Qt::FastTransformation));
    lbl->updatePos();
    //this line causes the vtable error
    //Player *player = new Player(0,700,new Weapon("fist"));
}

void gameWidget::frame()
{
    //timerTest++;
    //qDebug() << timerTest << endl;
}

void gameWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(player->getPos().x() >= 20)
        {
            player->moveLeft();
            lbl->updatePos();
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(player->getPos().x() <= 1004)
        {
            player->moveRight();
            lbl->updatePos();
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        qDebug() << "pow pow" << endl;
    }
}

gameWidget::~gameWidget()
{
    timer->stop();
    delete ui;
}
