#include "save.h"
#include <QFile>
#include <QTextStream>


void Save::saveScore(Map& map)
{
    Player savePlayer = map.getPlayer();
    QFile saveScore(filename);
    saveScore.open(QIODevice::WriteOnly | QIODevice::Text);
    savePlayer.saveScore(&saveScore);
    QTextStream out(&saveScore);
    out << "*";
    saveScore.close();
}

void saveWorld()
{
    //Not Implemented yet
    //TODO Save the state of the map, enemies, players, and obstacles
}

void processScores(QString loadMe)
{
    QTextStream load(&loadMe);
    QString line;

    //while (line != "*")
    for (int i = 0; i < 10; i++) //Temporarily loads the first 10 high score entries
                                 //until more sophisticated scores sorting and management
                                 //can be written
    {
        line = load.readLine();

        //TODO Places top 10 scores onto high scores window
        //We could also do the score sorting (and file cleanup?) here
    }
}


void loadScores(QString filename)
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
