#include "save.h"
#include <QFile>
#include <QTextStream>
#include <vector>
using namespace std;


void Save::saveScore(World& world)
{
    savePlayer = world.getPlayer();
    QFile saveScore(scoreFile);
    saveScore.open(QIODevice::WriteOnly | QIODevice::Text);
    savePlayer.saveScore(&saveScore);
    QTextStream out(&saveScore);
    out << "*";
    saveScore.close();
}

void Save::saveWorld(World& world)
{
    //TODO Save the state of the map, enemies, players, and obstacles
    QFile saveState(worldFile);
    saveState.open(QIODevice::WriteOnly | QIODevice::Text);
    savePlayer = world.getPlayer();
    savePlayer.saveState(&saveState);
    qDebug() << "Attempting to save enemies";
    qDebug() << "Attempting to get the enemies vector from world";
    std::vector<Enemy*> enemies = world.getEnemies();
    QTextStream save(&saveState);
    saveEnemy->saveState(&saveState);
    qDebug() << "Saved Enemies?";

    saveState.close();
}



void Save::loadScores(QString filename)
{
    QFile inFile(filename);

    if (!inFile.exists())
    {
        qDebug() << QString::fromLocal8Bit("File does not exist");
        return;
    }

    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    QTextStream in(&inFile);
    QString load = in.readAll();

    //processScores(load);
    inFile.close();
}
