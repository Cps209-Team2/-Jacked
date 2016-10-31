#include "save.h"
#include "player.h"

void Save::saveScore()
{
    Player *savePlayer = new Player();
    QFile saveScore(filename);
    savePlayer->saveScore(&saveScore);
}

void saveWorld()
{

}
