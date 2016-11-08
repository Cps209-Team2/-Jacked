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
#include "startwindow.h"

namespace Ui {
class gameWidget;
}

class gameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit gameWidget(QWidget *parent = 0);
    void playerMove();
    void enemyMove();
    void collide();
    void lblUpdate();
    ~gameWidget();
    std::vector<MovableLabel*> getElbls() { return elbls;}
    void begin();


private:
    Ui::gameWidget *ui;
    QTimer *timer;
    int timerTest;

    int pixChange;
    int enemyPixChange;

    bool movLeft;
    bool movRight;

    bool jump;
    bool falling;
    bool isGrounded;
    int hitCount;

    QWidget *start;


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
