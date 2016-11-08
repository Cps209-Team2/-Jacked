#include "highscoreswindow.h"
#include "ui_highscoreswindow.h"

HighScoresWindow::HighScoresWindow(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::HighScoresWindow)
{
    this->parent = dynamic_cast<StartWindow*>(parent)->getStart();
    ui->setupUi(this);

    /*
    scores = them.getThem();
    for (unsigned i = 0; i < scores->getScoreInfo().size(); ++i) {
        names += scores->getScoreInfo().at(i);
        names += "\n";

    }
    newLabel->setText(names);
    newLabel->setGeometry(100,700,100,100);

    /* for (unsigned i = 0; i < labels.size(); ++i) {
         //oldLabel = labels.at(i);
         //oldLabel->setGeometry();
         labels.at(i)->setGeometry(100*i,100*i,60,60);
         //labels.at(i).show();
     }*/


}


HighScoresWindow::~HighScoresWindow()
{
    delete ui;
}

void HighScoresWindow::on_pbClose_clicked()
{
    this->hide();
    parent->show();
    parent->setFocus();

}
