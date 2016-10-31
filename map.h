#ifndef MAP_H
#define MAP_H


#include <vector>
#include <string>
#include <istream>
#include <sstream>
#include <iostream>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QFile>
#include "obstacle.h"
#include "entity.h"
#include "player.h"

class Map
{
    int lvl;
    double height, width;
    Entity *player;
    std::vector<Obstacle*> obstacles;
    std::vector<Entity*> enemies;
    int currentScore;

public:
    Map();
    void setPlayer(Entity *character) { player = character; } //spawns player

    void create();//initializes new lvl
    void loadFile(QString filename);//loads saved map
    static void save(QString filename);
    void processLevel(QString level); // adds all game variables to the vectors
    void eSpawn();//spawns enemies
    void advance();//advances map to next lvl;
    void reset(); //removes all enemy and obstacle objects and allows for a new level
    void addScore(int plus) { currentScore += plus; }
    Entity& getPlayer() { return *player; }
    Entity* _Player() { return player; }
    std::vector<Entity*> getEnemies() {return enemies;}
    std::vector<Obstacle*> getObstacles() { return obstacles; }
};

#endif // MAP_H
