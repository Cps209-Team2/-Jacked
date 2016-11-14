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

//comments required by Bill, Kyle
class World
{
    int lvl;
    Player *player;
    std::vector<Obstacle*> obstacles; // not implemented
    std::vector<Enemy*> enemies; //enemies still alive
    std::vector<Enemy*> trashbin; // destroyed enemies
    int currentScore;

    //Singleton Implementation
    static World *instance_;
    explicit World(const World& that) = delete;
    World() {}
public:
    //sets entity passed in as either player or enemy. If enemy, it is placed in the enemies vector.  If player, overwrites current player
    void addEntity(Entity *obj);

    static World &instance();

    void create();//initializes new lvlb
    void loadFile(QString filename);//loads saved map
    static void saveScore(QString filename);
    void processLevel(QString level); // adds all game variables to the vectors
    void advance();//advances map to next lvl;
    void reset(); //removes all enemy and obstacle objects and allows for a new level
    void addScore(int plus) { currentScore += plus; }

    // places enemy from enemies vector into trashbin.  Used to clean up destroyed enemies
    void trash(int ID);

    //getters
    Player& getPlayer() { return *player; }
    Player* _Player() { return player; }
    std::vector<Enemy*>& getEnemies() {return enemies;}
    std::vector<Obstacle*>& getObstacles() { return obstacles; }
    int getLevel() { return lvl; }


    ~World();
};

#endif // MAP_H
