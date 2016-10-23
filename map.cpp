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
    void Map::create(int level)
{
        if (level == 1)
        {
            //create level 1
        }
        else if (level == 2)
        {
            //create level 2
        }
        else if (level == 3)
        {
            //create level 3
        }
        /*
        else if (level == 4)
        {
            //create level 4
        }
        */
        else
        {
            //throw std::InvalidArgumentException
        }
    reset();
    //void Map::loadFile(filename);
}

//loads saved map //features
void Map::loadFile(std::string filename) {

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
    lvl++;
    create();
}



