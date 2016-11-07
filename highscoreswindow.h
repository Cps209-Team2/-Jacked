#ifndef HIGHSCORESWINDOW_H
#define HIGHSCORESWINDOW_H

#include <QWidget>

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
};

#endif // HIGHSCORESWINDOW_H
