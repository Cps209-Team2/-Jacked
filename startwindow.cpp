#include <QApplication>
#include <QMessageBox>
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
    //help = new helpWidget(this);
    //help->hide();
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

//show a helpful information window
void StartWindow::on_pbHelp_clicked()
{
    //help->show();
    //help->setFocus();
    QMessageBox msgHelp;
    msgHelp.setText("This is where the help screen will go.");
    msgHelp.exec();
}

void StartWindow::on_pbHighscores_clicked()
{
    //show the highscores
    QMessageBox msgBox;
    msgBox.setText("This is where the highscores will go.");
    msgBox.exec();
}
