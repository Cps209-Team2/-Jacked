#ifndef MAP_H
#define MAP_H

class Map
{
    int lvl;
    Player *player;
    vector<Obstacles*> obstacles;
    vector<Enemy*> enemies;


public:
    create();//initializes new lvl
    loadFile(ifstream&);//loads saved map //features
    spawn(); //spawns player
    eSpawn();//spawns enemies
    advance();//advances map to next lvl;
    Map();
};

#endif // MAP_H
