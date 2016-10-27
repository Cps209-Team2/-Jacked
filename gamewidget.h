#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <entity.h>
#include <movablelabel.h>
#include "player.h"

namespace Ui {
class gameWidget;
}

class gameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit gameWidget(QMainWindow *parent = 0);
    ~gameWidget();

private:
    Ui::gameWidget *ui;
    QTimer *timer;
    int timerTest;
    Player *player;
    MovableLabel *lbl;

private slots:
    void frame();
    void keyPressEvent(QKeyEvent *event);
};

#endif // GAMEWIDGET_H
