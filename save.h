#ifndef SAVE_H
#define SAVE_H

#include <QString>
#include <QFile>
#include "world.h"
#include "player.h"
#include "enemy.h"
#include <vector>

class Save
{
    QString filename;
public:
    Save(QString initFilename): filename(initFilename) {};
    void saveScore(World *world);
    void saveWorld();
    void loadScores(QString filename);
    void processScores(QString load);
};

#endif // SAVE_H
