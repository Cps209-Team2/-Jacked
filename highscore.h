#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <fstream>
#include <string>
#include <vector>
#include <QString>
using namespace std;

class highscore {
    vector<int> highScores;
    vector<QString> names;
public:
    highscore();
    vector<int>* getHighScores() { return& highScores; }
    vector<QString>* getNames() { return& names; }
    void addHighScore(int highScore);
    void addName(QString name);
};

#endif // HIGHSCORE_H
