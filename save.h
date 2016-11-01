#ifndef SAVE_H
#define SAVE_H

#include <QString>
#include <QFile>
#include "map.h"
#include "player.h"
#include "map.h"
#include "enemy.h"
#include <vector>

class Save
{
    QString filename;
public:
    Save(QString initFilename): filename(initFilename) {};
    void saveScore(Map& map);
    void saveWorld();
    void loadScores(QString filename);
};

#endif // SAVE_H
