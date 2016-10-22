#include "map.h"


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
    Map.reset();
    Map.loadFile();
}

//loads saved map //features
void Map::loadFile(string filename) {

}

//spawns player
void Map::spawn() {

}

//spawns enemies
void Map::eSpawn() {
    for (int i = 0; i < this->enemies.size(); ++i)
    {

    }
}

//advances map to next lvl;
void Map::advance() {
    Map.lvl++;
    Map.create();
}



