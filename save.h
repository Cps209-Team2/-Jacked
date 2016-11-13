#ifndef SAVE_H
#define SAVE_H

#include <QString>
#include <QFile>
#include "world.h"
#include "player.h"
#include "enemy.h"
#include <vector>
using namespace std;

class Save
{
    QString scoreFile;
    QString worldFile;
    Player savePlayer;
    Enemy *saveEnemy;
    QString line;
    std::vector<QString*> scoreInfo;
public:
    Save() {}
    Save(QString initScoreFile, QString initWorldFile): scoreFile(initScoreFile), worldFile(initWorldFile) {}
    Save(QString File): scoreFile(File) { }


    void saveScore(World& world);
    void saveWorld(World& world);

    void loadScores(QString filename);
    void processScores(QString load);
    //~Save(){ for(unsigned i = 0; i< scoreInfo.size(); ++i){delete scoreInfo->at(i);} delete scoreInfo; }

    //getters
    std::vector<QString*> getScoreInfo() {return scoreInfo;}
    //void pushScoreInfo(QString param) {scoreInfo.push_back(param);}
    QString getLine() {return line;}
};

#endif // SAVE_H
