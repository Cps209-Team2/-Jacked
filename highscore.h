#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <iostream>
#include <QDebug>
#include <string>
#include <vector>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QFile>
#include "save.h"
using namespace std;

class highscore {
    vector<int> scores;
    vector<string> names;
    //Save *scoreFile;
public:
    highscore() {
        QFile file("Highscores.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
           qDebug() << "File could not open." << endl;
        }
        qDebug() << "FIle is open" << endl;

        while(!file.atEnd()) {
            cout << "Inside loop" << endl;
            QString line = file.readLine();
            QStringList list = line.split(":");
            names.push_back(list.at(0).toStdString());
            scores.push_back(list.at(1).toInt());
        }
        qDebug() << "File is read" << endl;
        file.close();
        qDebug() << "FIle is closed" << endl;
    }
    highscore(QString saveFile);

    //getter methods
    vector<int> getHighScores() { return scores; }
    vector<string> getNames() { return names; }

    //setter methods
    void addHighScore(int highScore);
    void addName(string name);
    //Save* getSave() {return scoreFile;}
    //Save* getThem() {return scoreFile;}
};

#endif // HIGHSCORE_H
