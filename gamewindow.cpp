#include <QDebug>
#include <QKeyEvent>
#include "gamewindow.h"
#include "Player.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    //connect(this, SIGNAL(keyPressEvent(QEvent*)),this,SLOT(key_pressed(QEvent*)));
}

void GameWindow::keyPressEvent()
{
    qDebug() << "test" << endl;
}

void GameWindow::keyPressEvent(QEvent *event)
{
    qDebug() << "test" << endl;
}

/*
void GameWindow::key_pressed(QEvent *event)
{
    qDebug() << "test" << endl;
    if(event->type() == Qt::LeftArrow)
    {

    }
    else if (event->type() == Qt::RightArrow)
    {

    }
    else if(event->type() == Qt::UpArrow)
    {

    }
}
*/
GameWindow::~GameWindow()
{
    delete ui;
}
