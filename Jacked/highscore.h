#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <istream>
using namespace std;

class highscore {

    istream *file;
    int points, time;

    highscorce();
    addTime(){time++;}
    writeFile();
    showBestTime();
    string scoreList();
};





#endif // HIGHSCORE_H
