#include <fstream>
#include <QMessageBox>
#include "map.h"
#include "entity.h"
#include "enemy.h"

using namespace std;

Map::Map()
{
    height = 500;
    width = 1000;
}
/*
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
*/
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
    QFile outFile(QString::fromLocal8Bit("out.txt"));
    outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&outFile);
    QString line;
    while (line != "*")
    {
        line = level.readLine();
        //out << line;

        if (line == "#Jacked")
        {
            //skip for now, unless we need to know the level number
        }
        else if (line == "#Obstacles")
        {
            int xPos;
            int yPos;
            QChar c;
            line = level.readLine();
            out << line;

            for (int i = 0; i < line.length(); ++i)
            {
                if (c == ':' && line.at(0) == 'p')
                {
                    xPos = line.at(i + 1).digitValue();
                }
                else if (c == ',')
                {
                    yPos = line.at(i + 1).digitValue();
                }
            }
            obstacles.push_back(new Obstacle(xPos, yPos));
        }
        else if (line == "#Player")
        {
            //Set the player's coordinates and weapon
            int xPos;
            int yPos;
            QChar c;
            QString weapon;
            line = level.readLine();
            //In here, get the object name that is supposed to be created
            line = level.readLine();
            out << line;

            for (int i = 0; i < line.length(); ++i)
            {
                if (c == ':' && line.at(0) == 'p')
                {
                    //the next thing is the x coordinate
                    xPos = line.at(i + 1).digitValue();
                }

                else if (c == ':' && line.at(0) == 'w')
                {
                    for (int ind = i + 1; ind < line.length(); ind++)
                    {
                        weapon += line.at(ind);
                    }
                    out << weapon;
                }
                else if (c == ',')
                {
                    //the next thing is the y coordinate
                    yPos = line.at(i + 1).digitValue();
                }
            }
            //Player *player = new Player(xPos, yPos, new Weapon(weapon));
        }
        else if (line == "#Enemies")
        {
            //set up the world's enemies
            int xPos;
            int yPos;
            int type;
            QChar c;
            QString weapon;
            line = level.readLine();
            //In here, get the object name that is supposed to be created - maybe we can have $type in the file?
            line = level.readLine();
            out << line;
            for (int i = 0; i < line.length(); ++i)
            {
                if (c == ':' && line.at(0) == 'p')
                {
                    //the next thing is the x coordinate
                    xPos = line.at(i + 1).digitValue();
                }

                else if (c == ':' && line.at(0) == 'w')
                {
                    for (int ind = i + 1; ind < line.length(); ind++)
                    {
                        weapon += line.at(ind);
                    }
                    out << weapon;
                }
                else if (c == ',')
                {
                    //the next thing is the y coordinate
                    yPos = line.at(i + 1).digitValue();
                }
                else if (line.at(0) == '$')
                {
                    type = line.at(1).digitValue();
                }
            }
            enemies.push_back(new Enemy(xPos, yPos, new Weapon(weapon)));
        }
    }
}

/*
//spawns enemies
void Map::eSpawn() {
    for (int i = 0; i < this->enemies.size(); ++i)
    {
        //spawn enemy
    }
}
*/

//advances map to next lvl;
void Map::advance() {
    lvl++;
    //create();
}



