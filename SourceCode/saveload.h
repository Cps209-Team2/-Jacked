#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <fstream>
#include <string>
#include "map"

class Save
{
    ifstream& loadfile;
    static SaveLoad *instnace;
    World *world;

    SaveLoad();

public:
static SaveLoad* getInstance();//singleton method
static void writeFile();//writes map features and player fatures to file
static file loadFile();//returns ifstream file


};

#endif // SAVELOAD_H
