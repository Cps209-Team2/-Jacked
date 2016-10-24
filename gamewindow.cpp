#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "Player.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    Player one(0,0, NULL);
}

void GameWindow::keyPressEvent(QEvent *event)
{
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

GameWindow::~GameWindow()
{
    delete ui;
}
