#include "highscoreswindow.h"
#include "ui_highscoreswindow.h"

//at construction a highscore object is created using the text file
//the scores are then displayed by the labels on the window
HighScoresWindow::HighScoresWindow(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::HighScoresWindow)
{

    this->parent = dynamic_cast<StartWindow*>(parent)->getStart();
    ui->setupUi(this);
    them = new highscore("Highscore.txt");
    for (unsigned i = 0; i < them->getNames().size(); ++i) {
       QString scoreline = QString::fromStdString(them->getNames().at(i));
               scoreline += "\nScore: ";
               scoreline += QString::number(them->getHighScores().at(i));

       parsedScores.push_back(scoreline);
    }

    ui->lblHighscore1->setText(parsedScores.at(0));
    ui->lblHighscore2->setText(parsedScores.at(1));
    ui->lblHighscore3->setText(parsedScores.at(2));
    ui->lblHighscore4->setText(parsedScores.at(3));
    ui->lblHighscore5->setText(parsedScores.at(4));


}


HighScoresWindow::~HighScoresWindow()
{
    delete ui;
}

//hide the highscores window and show the mainwindow.
void HighScoresWindow::on_pbClose_clicked()
{
    this->hide();
    parent->show();
    parent->setFocus();

}
