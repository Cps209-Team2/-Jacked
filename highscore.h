#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <fstream>
#include <string>
#include <vector>
#include <QString>
#include "save.h"
using namespace std;

class highscore {
    vector<int> highScores;
    vector<QString> names;
    Save *scoreFile;
public:
    highscore() {}
    highscore(QString saveFile);
    vector<int>* getHighScores() { return& highScores; }
    vector<QString>* getNames() { return& names; }
    Save* getThem() {return scoreFile;}
    void addHighScore(int highScore);
    void addName(QString name);
};

#endif // HIGHSCORE_H
