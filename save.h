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
    QString scoreFile;
    QString worldFile;
public:
    Save(QString initScoreFile, QString initWorldFile): scoreFile(initScoreFile), worldFile(initWorldFile) {}
    void saveScore(World *world);
    void saveWorld(World *world);
    void loadScores(QString filename);
    void processScores(QString load);
};

#endif // SAVE_H
