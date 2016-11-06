#include <QApplication>
#include <QMessageBox>
#include "startwindow.h"
#include "ui_startwindow.h"
#include "gamewidget.h"
#include "help.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    game = new gameWidget(this);
    game->hide();
    helpScreen = new help(this);
    helpScreen->hide();
    //help = new helpWidget(this);
    //help->hide();
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_btnCheat_clicked()
{
    // Start cheat mode!
    // Player gets invincibility (intangibility)
    // and gives greater damage
    this->cheatMode = !(this->cheatMode);
}

void StartWindow::on_btnPlay_clicked()
{
    ui->centralwidget->hide();
    //game = new gameWidget(this);
    //game->hide();
    game->show();
    game->setFocus();
    game->begin();

    //start the game!!!
    //newGame.show();

}

//show a helpful information window
void StartWindow::on_pbHelp_clicked()
{
    ui->centralwidget->hide();
    helpScreen->show();
    helpScreen->setFocus();
    //QMessageBox msgHelp;
    //msgHelp.setText("This is where the help screen will go.");
   //msgHelp.exec();
}

void StartWindow::on_pbHighscores_clicked()
{
    //show the highscores
    QMessageBox msgBox;
    msgBox.setText("This is where the highscores will go.");
    msgBox.exec();
}
