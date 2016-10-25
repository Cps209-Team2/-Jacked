#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class highscore {

    istream *file;
    vector<int> scores;
    int currentScore;
public:
    highscore();
    void addTime(){}
    //void addDistance(int initDistance){distance = initDistance;}
    void writeFile(string filename);
    void showBestTime();
    string scoreList();
};

#endif // HIGHSCORE_H
