#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QKeySequence>
#include "gamewidget.h"
#include "help.h"

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

    void on_btnPlay_clicked();

    void on_pbHelp_clicked();

    void on_pbHighscores_clicked();

    void on_btnCheat_clicked();

    void on_helpClosed();

private:
    gameWidget *game;
    help *helpScreen;
    //helpWidget *help;
    Ui::StartWindow *ui;


};

#endif // STARTWINDOW_H
