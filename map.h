#ifndef MAP_H
#define MAP_H


#include <vector>
#include <string>
#include <istream>
#include "Player.h"
#include "Enemy.h"
#include "obstacle.h"

class Map
{
    int lvl;
    double height, width;
    Player *player;
    std::vector<Obstacle*> obstacles;
    std::vector<Enemy*> enemies;
    int currentScore;


public:
    Map();
    void create();//initializes new lvl
    void loadFile(std::string filename);//loads saved map
    void spawn(); //spawns player
    void eSpawn();//spawns enemies
    void advance();//advances map to next lvl;
    void reset(); //removes all enemy and obstacle objects and allows for a new level
    void addScore(int plus) { currentScore += plus; }




};

#endif // MAP_H
