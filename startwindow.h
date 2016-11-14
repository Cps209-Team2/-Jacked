#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QKeySequence>
#include "gamewidget.h"
#include "help.h"
#include "highscore.h"
#include "highscoreswindow.h"

namespace Ui {
class StartWindow;
}

class gameWidget;
class HighScoresWindow;

class StartWindow : public QMainWindow
{
    Q_OBJECT
private:

    gameWidget *game;
    help *helpScreen;
    HighScoresWindow *highscoreScreen;
    highscore themScores;
    //helpWidget *help;
    Ui::StartWindow *ui;
    bool newWindow;


public:
    explicit StartWindow(QMainWindow *parent = 0);

    // returns this for other widgets to reference
    QWidget *getStart();

    //comments required by Bill, Kyle
    bool cheatMode = false;
    ~StartWindow();


private slots:

    void on_btnPlay_clicked();

    void on_pbHelp_clicked();

    void on_pbHighscores_clicked();

    void on_btnCheat_clicked();

    void on_helpClosed();



};

#endif // STARTWINDOW_H
