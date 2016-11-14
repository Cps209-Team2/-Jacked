#ifndef HIGHSCORESWINDOW_H
#define HIGHSCORESWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include "startwindow.h"
#include "highscore.h"

namespace Ui {
class HighScoresWindow;
}

class HighScoresWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HighScoresWindow(QMainWindow *parent = 0);

    ~HighScoresWindow();

private slots:
    void on_pbClose_clicked();

private:
    Ui::HighScoresWindow *ui;
    highscore *them;
    vector<QString> parsedScores;
    QLabel *newLabel;
    Save *scores;
    QString names;
    std::vector<QLabel*> labels;
    QWidget *parent;

};

#endif // HIGHSCORESWINDOW_H
