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

    // moves player label and object together based on key events
    void playerMove();

    // moves enemies based on player position
    void enemyMove(Enemy *obj);

    // checks for collision among ALL entities in the game
    // also handles entities taking DMG and dying
    void collide(CollisionInfo *data);

    // updates label position for player object
    void lblUpdate();

    // updates label position for enemy objects in world
    void elblUpdate();

    // clears all entities from world
    void reset();

    // initializes world from .txt file
    void loadLvl();

    // loads player into gameWidget from world
    void spawnPlayer();

    // returns timer for use in escmenu and highscores
    QTimer* getTimer() { return timer; }

    ~gameWidget();

private:

    Ui::gameWidget *ui;

    QWidget *start;

    QTimer *timer;

    // used for changing animations after being hit
    int pixChange;
    int enemyPixChange;

    // variables initialized for convenient reference
    Player *player;
    PlayerLabel *lbl;

    //contains all labels created for accessibility
    std::vector<MovableLabel*> elbls;

    World& world = World::instance();

    EscMenu* escMenu;

    // checks if gameWidget is open
    bool isOpen;


private slots:
    // updates every tick of the timer
    void frame();

    // used to manipulate player position
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // GAMEWIDGET_H
