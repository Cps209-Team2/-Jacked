#include <QApplication>
#include "startwindow.h"
#include "ui_startwindow.h"
#include "gamewidget.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    game = new gameWidget(this);
    game->hide();
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_cheatBtn_clicked()
{
    // Start cheat mode!
    // Player gets invincibility (intangibility)
    // and gives greater damage
    this->cheatMode = !(this->cheatMode);
}

void StartWindow::on_btnPlay_clicked()
{
    ui->centralwidget->hide();
    game->show();
    game->setFocus();
    //start the game!!!
    //newGame.show();

}
