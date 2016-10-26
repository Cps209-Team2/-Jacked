#include "map.h"
#include <fstream>
#include <QMessageBox>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>

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

       QFile file(filename);
       QFile output ("out.txt");

       //string line;

       cout << "Loading File" << endl;

       if (!file.exists())
       {
           cout << "Could not read file!" << endl;
           //QMessageBox::warning(this, QString::toLocal8Bit("I/O Error"), QString::toLocal8Bit("Could not read file!"));
       }

       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
               return;
       }
       if (!output.open(QIODevice::WriteOnly | QIODevice::Text))
           return;

       QTextStream in(&file);
       QTextStream out(&output);

       while (!in.atEnd())
       {
           QString line = file.readLine();
           out << line;
       }
       file.close();
       output.close();
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



