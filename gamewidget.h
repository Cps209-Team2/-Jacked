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
#include "startwindow.h"
#include "escmenu.h"

namespace Ui {
class gameWidget;
}

class gameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit gameWidget(QWidget *parent = 0);
    void playerMove();
    void enemyMove(Enemy *obj);
    void collide(CollisionInfo *data);
    void lblUpdate();
    void elblUpdate();
    ~gameWidget();
    std::vector<MovableLabel*> getElbls() { return elbls; }
    void reset();
    void updatePlayerCondition();

    void spawnPlayer();
    void loadTestLvl();
    //void loadLvl1();

    QTimer* getTimer() { return timer; }


private:
    Ui::gameWidget *ui;
    QTimer *timer;
    int timerTest;

    int pixChange;
    int enemyPixChange;

    //all of these variables will be placed in their proper classes later
    //bool movLeft;
    //bool movRight;

    bool jump;

    int hitCount;
    int enemyHitCount;

    QWidget *start;

    // testing variables
    Player *player;
    Enemy *enemy;
    PlayerLabel *lbl;
    MovableLabel *enemyLbl;
    std::vector<MovableLabel*> elbls;
    World& world = World::instance();
    EscMenu* escMenu;
    bool isOpen;


private slots:
    void frame();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // GAMEWIDGET_H
