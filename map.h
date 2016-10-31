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
#include "enemy.h"

class Map
{
    int lvl;
    Player *player;
    std::vector<Obstacle*> obstacles;
    std::vector<Enemy*> enemies;
    int currentScore;

public:
    Map();

    void setPlayer(Player *character) { player = character; } //spawns player

    void create();//initializes new lvl
    void loadFile(QString filename);//loads saved map
    static void save(QString filename);
    void processLevel(QString level); // adds all game variables to the vectors
    void eSpawn();//spawns enemies
    void advance();//advances map to next lvl;
    void reset(); //removes all enemy and obstacle objects and allows for a new level
    void addScore(int plus) { currentScore += plus; }
    Player& getPlayer() { return *player; }
    Player* _Player() { return player; }
    std::vector<Enemy*> getEnemies() {return enemies;}
    std::vector<Obstacle*> getObstacles() { return obstacles; }

    ~Map();
};

#endif // MAP_H
