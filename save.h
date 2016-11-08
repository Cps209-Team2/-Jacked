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
    Player savePlayer;
    Enemy *saveEnemy;
    std::vector<QString> scoreInfo;
public:
    Save() {}
    Save(QString initScoreFile, QString initWorldFile): scoreFile(initScoreFile), worldFile(initWorldFile) {}
    Save(QString File): scoreFile(File) { }
    void saveScore(World *world);
    void saveWorld(World *world);
    void loadScores(QString filename);
    void processScores(QString load);

    //getters
    std::vector<QString> getScoreInfo() {return scoreInfo;}
};

#endif // SAVE_H
