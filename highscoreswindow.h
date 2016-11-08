#ifndef HIGHSCORESWINDOW_H
#define HIGHSCORESWINDOW_H

#include <QWidget>
#include <QLabel>
#include "highscore.h"

namespace Ui {
class HighScoresWindow;
}

class HighScoresWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HighScoresWindow(QWidget *parent = 0);
    ~HighScoresWindow();

private:
    Ui::HighScoresWindow *ui;
    highscore them;
    QLabel newLabel;
    Save *scores;
    std::vector<QLabel> labels;
};

#endif // HIGHSCORESWINDOW_H
