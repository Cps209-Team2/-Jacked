#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <QFile>
#include <QTextStream>
#include <string>
#include "map.h"
#include "player.h"
#include "enemy.h"

class Save
{
    QFile saveFile;
    QTextStream save;

    Map *world;
    Player *player;
    Enemy *enemy;
public:
    Save(Map *initWorld, Player *initPlayer, Enemy *initEnemy): world(initWorld), player(initPlayer), enemy(initEnemy){}
    static void saveWorld();
    static void saveScore();


};

#endif // SAVELOAD_H
