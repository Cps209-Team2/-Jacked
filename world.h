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
#include "enemy.h"
#include "player.h"
class Enemy;
class World
{
    int lvl;
    Player *player;
    std::vector<Obstacle*> obstacles;
    std::vector<Enemy*> enemies;
    std::vector<Enemy*> trashbin;
    int currentScore;
    static World *instance_;

    explicit World(const World& that) = delete;


public:
    World(){ }
    void setPlayer(Player *character) { player = character; } //spawns player

    static World *instance();
    //void setPlayer(Entity *character) { player = character; } //spawns player

    void create();//initializes new lvlb
    void loadFile(QString filename);//loads saved map
    //void addEnemy(Enemy *newEnemy) { enemies.push_back(newEnemy); }
    static void saveScore(QString filename);
    void processLevel(QString level); // adds all game variables to the vectors
    void eSpawn();//spawns enemies
    void advance();//advances map to next lvl;
    void reset(); //removes all enemy and obstacle objects and allows for a new level
    void addScore(int plus) { currentScore += plus; }

    void trash(Enemy *);

    //getters
    Player& getPlayer() { return *player; }
    Player* _Player() { return player; }
    std::vector<Enemy*>& getEnemies() {return enemies;}
    std::vector<Obstacle*>& getObstacles() { return obstacles; }
    int getLevel() { return lvl; }


    ~World();
};

#endif // MAP_H
