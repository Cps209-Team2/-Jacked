#include "save.h"
#include "player.h"
#include "map.h"
#include "enemy.h"
#include <vector>

void Save::saveScore(Map& map)
{
    Player savePlayer = map.getPlayer();
    QFile saveScore(filename);
    saveScore.open(QIODevice::WriteOnly | QIODevice::Text);
    savePlayer.saveScore(&saveScore);

}

void saveWorld()
{

}
