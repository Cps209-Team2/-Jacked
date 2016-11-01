#include "save.h"


void Save::saveScore(Map& map)
{
    Player savePlayer = map.getPlayer();
    QFile saveScore(filename);
    saveScore.open(QIODevice::WriteOnly | QIODevice::Text);
    savePlayer.saveScore(&saveScore);

}

void saveWorld()
{
    //Not Implemented yet
    //TODO Save the state of the map, enemies, players, and obstacles
}

void loadScores(QString filename)
{

}
