#include "map.h"
#include <fstream>
#include <QMessageBox>

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
    //Map::loadFile(1);
    int num = 1;
    //string line = file.getline();
    //if (line != NULL) {Player one = new Player() }
    //if (file) {
        //read player pos
        //read player weapon
        //loop through enemies
    //}
}



//loads saved or default map
void Map::loadFile(QString filename) {

       QFile inFile(filename);

       if (!inFile.exists())
       {
           qDebug() << QString::fromLocal8Bit("File does not exist");
           return;
       }

       if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
               return;

       QTextStream in(&inFile);
       QString level = in.readAll();

       processLevel(level);
       inFile.close();
}

// Puts all the game variables into the correct vector
void Map::processLevel(QString levels)
{
    QTextStream level(&levels);
    //QFile outFile(QString::fromLocal8Bit("out.txt"));
    //outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    //QTextStream out(&outFile);
    QString line;
    while (line != "*")
    {
        line = level.readLine();
        qDebug() << line;
    }
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



