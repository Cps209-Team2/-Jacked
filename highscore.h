#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class highscore {
    vector<int> highScores;
public:
    highscore();
    vector<int>* getHighScore() { return& highScores; }
    void addHighScore(int highScore);
};

#endif // HIGHSCORE_H
