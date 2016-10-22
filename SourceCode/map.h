#ifndef MAP_H
#define MAP_H

#include "Enemy.h"
#include "Player.h"
#include <fstream>
#include <vector>

class Map
{
    int lvl;
    double height, width;
    Player *player;
    vector<Obstacles*> obstacles;
    vector<Enemy*> enemies;


public:
    Map();
    void reset();
    void create();//initializes new lvl
    void loadFile(ifstream&);//loads saved map //features
    Player spawn(); //spawns player
    Enemy eSpawn();//spawns enemies
    void advance();//advances map to next lvl;

};

#endif // MAP_H
