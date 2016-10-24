#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

    GameWindow newGame;
    bool cheatMode = false;

private slots:

    void on_startBtn_clicked();

    void on_cheatBtn_clicked();

    void on_btnPlayer_clicked();

private:
    Ui::StartWindow *ui;


};

#endif // STARTWINDOW_H
