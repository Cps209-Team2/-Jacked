#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <fstream>
#include <string>
using namespace std;

class highscore {

    istream *file;
    int points, time;

public:
    highscore();
    void addTime(){time++;}
    void writeFile(string filename);
    void showBestTime();
    string scoreList();
};

#endif // HIGHSCORE_H
