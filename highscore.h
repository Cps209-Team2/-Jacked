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
    highscore();
    //highscore(QString saveFile);

    //getter methods
    vector<int> getHighScores() { return scores; }
    vector<string> getNames() { return names; }

    //setter methods
    void addHighScore(int highScore);
    void addName(string name);

};

#endif // HIGHSCORE_H
