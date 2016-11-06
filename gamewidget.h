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
#include "world.h"
#include "playerlabel.h"
#include "enemylabel.h"

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
    void lblUpdate();
    ~gameWidget();
    std::vector<MovableLabel*> getElbls() { return elbls;}
    void begin();

private:
    Ui::gameWidget *ui;
    QTimer *timer;
    int timerTest;

    int pixChange;

    bool movLeft;
    bool movRight;

    bool jump;
    bool falling;
    bool isGrounded;
    bool hit;



    // testing variables
    Player *player;
    Enemy *enemy;
    PlayerLabel *lbl;
    MovableLabel *elbl;
    std::vector<MovableLabel*> elbls;
    World *world;


private slots:
    void frame();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // GAMEWIDGET_H
