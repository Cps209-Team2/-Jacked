#include <QApplication>
#include "startwindow.h"
#include "ui_startwindow.h"
#include "gamewindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{

    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_startBtn_clicked()
{

}

void StartWindow::on_cheatBtn_clicked()
{
    // Start cheat mode!
    // Player gets invincibility (intangibility)
    // and gives greater damage
}

void StartWindow::on_btnPlayer_clicked()
{
    //start the game!!!
    newGame.show();

}
