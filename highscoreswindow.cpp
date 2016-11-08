#include "highscoreswindow.h"
#include "ui_highscoreswindow.h"

HighScoresWindow::HighScoresWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HighScoresWindow)
{
    ui->setupUi(this);
    scores = them.getThem();
    for (int i = 0; i < scores->getScoreInfo().size(); ++i) {
        newLabel.setText(scores->getScoreInfo().at(i));
        labels.push_back(newLabel);
    }


}

HighScoresWindow::~HighScoresWindow()
{
    delete ui;
}
