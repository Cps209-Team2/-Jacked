#include <QApplication>
#include <QMessageBox>
#include "startwindow.h"
#include "ui_startwindow.h"
#include "ui_highscoreswindow.h"
#include "highscore.h"
#include "gamewidget.h"
#include "help.h"

StartWindow::StartWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    //game = new gameWidget(this);
    //game->hide();
    helpScreen = new help(this);
    helpScreen->hide();
    highscoreScreen = new HighScoresWindow(this);
    highscoreScreen->hide();
    connect(helpScreen, SIGNAL(destroyed()), this, SLOT(on_helpClosed()));

    //connect(highscoreScreen, SIGNAL(destroyed()),this, SLOT(on_pbHighscores_closed()));


    newWindow = true;
}

QWidget *StartWindow::getStart()
{
    return ui->centralwidget;
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

    game = new gameWidget(this);

    game->show();
    game->setFocus();

    newWindow = false;
}

//show a helpful information window
void StartWindow::on_pbHelp_clicked()
{
    ui->centralwidget->hide();
    //ui->centralwidget->hide();
    helpScreen->show();
    //ui->btnCheat->hide();
    ui->btnCheat->setVisible(false);
    //ui->btnPlay->hide();
    ui->btnPlay->setVisible(false);
    //ui->lblTitle->hide();
    ui->lblTitle->setVisible(false);
    //ui->pbHelp->hide();
    ui->pbHelp->setVisible(false);
    //ui->pbHighscores->hide();
    ui->pbHighscores->setVisible(false);
}

void StartWindow::on_helpClosed()
{

    ui->btnCheat->show();
    ui->btnCheat->show();
    ui->btnPlay->show();
    ui->lblTitle->show();
    ui->pbHelp->show();
    ui->pbHighscores->show();
}

void StartWindow::on_pbHighscores_clicked()
{
    ui->centralwidget->hide();
    highscoreScreen->show();
    //show the highscores
    //them = themScores.getSave()->getThem();
    /*QMessageBox msgBox;
    msgBox.setText("Highscorse will go here!!!");
    msgBox.exec(); */
 }

