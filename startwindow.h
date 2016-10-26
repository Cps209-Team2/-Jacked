#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QKeySequence>
#include "gamewidget.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

    bool cheatMode = false;

private slots:

    void on_cheatBtn_clicked();

    void on_btnPlay_clicked();

private:
    gameWidget *game;
    Ui::StartWindow *ui;


};

#endif // STARTWINDOW_H
