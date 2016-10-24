#include "map.h"
#include <fstream>
using namespace std;

Map::Map()
{
    height = 500;
    width = 1000;
}

void Map::reset() {
    //removes enemy objects
    for (int i = 0; i < this->enemies.size(); i++) {
        delete[] this->enemies.at(i);

    }
    this->enemies.clear();

    //removes obstacles
    for (int i = 0; i < this->obstacles.size(); i++) {
        delete[] this->obstacles.at(i);
    }
    this->obstacles.clear();

    //reset player
    //need to decide what to do
}

//initializes new lvl
void Map::create() {
    this->reset();
    this->loadFile();
    int num = 1;
    string line = file.getline();
    //if (line != NULL) {Player one = new Player() }
    //if (file) {
        //read player pos
        //read player weapon
        //loop through enemies
    //}
}

//loads saved map //features
void Map::loadFile(string filename) {
       file = new ifstream(filename);
}

//spawns player
void Map::spawn() {
        //spawn player
}

//spawns enemies
void Map::eSpawn() {
    for (int i = 0; i < this->enemies.size(); ++i)
    {
        //spawn enemy
    }
}

//advances map to next lvl;
void Map::advance() {
    Map.lvl++;
    Map.create();
}



