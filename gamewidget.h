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
#include "enemy.h"
#include "map.h"
namespace Ui {
class gameWidget;
}

class gameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit gameWidget(QMainWindow *parent = 0);
    void playerMove();
    void enemyMove();
    ~gameWidget();
    std::vector<MovableLabel*> getElbls() { return elbls;}

private:
    Ui::gameWidget *ui;
    QTimer *timer;
    int timerTest;

    bool movLeft;
    bool movRight;
    bool jump;
    bool isGrounded;
    bool hit;



    // testing variables
    Player *player;
    Enemy *enemy;
    MovableLabel *lbl;
    MovableLabel *elbl;
    std::vector<MovableLabel*> elbls;
    Map *world;


private slots:
    void frame();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // GAMEWIDGET_H
