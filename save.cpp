#include "save.h"
#include <QFile>
#include <QTextStream>
#include <vector>


void Save::saveScore(World *world)
{
    savePlayer = world->getPlayer();
    QFile saveScore(scoreFile);
    saveScore.open(QIODevice::WriteOnly | QIODevice::Text);
    savePlayer.saveScore(&saveScore);
    QTextStream out(&saveScore);
    out << "*";
    saveScore.close();
}

void Save::saveWorld(World *world)
{
    //TODO Save the state of the map, enemies, players, and obstacles
    QFile saveState(worldFile);
    saveState.open(QIODevice::WriteOnly | QIODevice::Text);
    savePlayer = world->getPlayer();
    savePlayer.saveState(&saveState);
    //*
    qDebug() << "Attempting to save enemies";
    qDebug() << "Attempting to get the enemies vector from world";
    std::vector<Entity*> enemies = world->getEnemies();
    qDebug() << "Entering for loop";
    for (int i = 0; i < enemies.size(); ++i)
    {
        qDebug() << "Getting the enemy stored at" << i;
        saveEnemy = dynamic_cast<Enemy*>(enemies.at(i));
        qDebug() << "Writing that enemy to the file";
        //Save enemies here
        saveEnemy->saveState(&saveState);
    }
    qDebug() << "Saved Enemies?";

    saveState.close();
    //*/
}

void Save::processScores(QString loadMe)
{
    QTextStream load(&loadMe);
    QString line;
    QString name;
    int score;

    //while (line != "*")
    for (int i = 0; i < 10; i++) //Temporarily loads the first 10 high score entries
                                 //until more sophisticated scores sorting and management
                                 //can be written
    {
        line = load.readLine();

        //TODO Places top 10 scores onto high scores window
        //We could also do the score sorting (and file cleanup?) here
        QStringList lineColon = line.split(':');
        name = lineColon.at(0);
        score = lineColon.at(1).toInt();

        //Put into High Score window
    }
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

    processScores(load);
    inFile.close();
}
