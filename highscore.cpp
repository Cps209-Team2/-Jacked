#include "highscore.h"

void highscore::addHighScore(int highScore)
{
    highScores.push_back(highScore);
    highScores.erase(highScores.end());
}
