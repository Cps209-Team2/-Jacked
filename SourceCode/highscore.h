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
    addTime(){time++;}
    writeFile(string filename);
    showBestTime();
    string scoreList();
};

#endif // HIGHSCORE_H
