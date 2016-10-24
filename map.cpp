#include "map.h"
#include <fstream>
#include <QMessageBox>
#include <iostream>
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
    //this->reset();
    Map::loadFile(":/Levels/DefaultLevels/lvl1.txt");
    int num = 1;
    //string line = file.getline();
    //if (line != NULL) {Player one = new Player() }
    //if (file) {
        //read player pos
        //read player weapon
        //loop through enemies
    //}
}
//loads saved map //features
void Map::loadFile(string filename) {
       ifstream file(filename);
       string line;
       //QString objectType;
       cout << "Loading File" << endl;
       //getline(file, line);

       /*
       cout << "File Opened" << endl;
       for (int i = 0; i <= 10; i++)
       {
           cout << getline(file, line) <<endl;
       }
       */
       while (file)
       {
           getline(file, line);
           /*
           if (line.substr(0) == "#")
           {
               //objectType = QString::fromLocal8Bit(line.substr(1,line.size()));
               //QMessageBox::information(this, QString::fromLocal8Bit("Object Type"), objectType);
               cout << line.substr(1, line.size()) << endl;

           }
           else if (line.substr(0) == "$")
           {
               // This means this is currently an enemy
               // TODO Process enemy
           }
           else if (line.substr(0) == "*")
           {
               break;
           }
           else
           {
               getline(file, line);
           }
           */
           cout << line << endl;
       }
       file.close();
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
    lvl++;
    //create();
}



