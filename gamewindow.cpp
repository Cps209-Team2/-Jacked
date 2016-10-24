#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
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
