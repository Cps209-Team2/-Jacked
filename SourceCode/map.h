#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "obstacle.h"

class Map
{
    int lvl;
    Player *player;
    std::vector<Obstacle*> obstacles;
    std::vector<Enemy*> enemies;


public:
    void create();//initializes new lvl
    void loadFile(std::string filename);//loads saved map //features
    void spawn(); //spawns player
    void eSpawn();//spawns enemies
    void advance();//advances map to next lvl;
    Map();
};

#endif // MAP_H
