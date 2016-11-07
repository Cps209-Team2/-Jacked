#include "highscoreswindow.h"
#include "ui_highscoreswindow.h"

HighScoresWindow::HighScoresWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HighScoresWindow)
{
    ui->setupUi(this);
}

HighScoresWindow::~HighScoresWindow()
{
    delete ui;
}
