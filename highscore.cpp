#include "highscore.h"

highscore::highscore(QString file) {
        scoreFile->processScores(file);
}

void highscore::addHighScore(int highScore)
{
    highScores.push_back(highScore);
    //highScores.erase(highScores.end()); //What does this do?
}

void highscore::addName(QString name)
{
    names.push_back(name);
}
