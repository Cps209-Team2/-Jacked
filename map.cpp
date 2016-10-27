#include <fstream>
#include <QMessageBox>
#include "map.h"
#include "entity.h"
#include "enemy.h"
#include <QDebug>
#include "player.h"

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
       //qDebug() << level;

       processLevel(level);
       inFile.close();
}

// Puts all the game variables into the correct vector
void Map::processLevel(QString levels)
{
    QTextStream level(&levels);
    QString line;
    while (line != "*")
    {
        line = level.readLine();
        if (line == "*")
        {
            break;
        }
        //qDebug() << line;
        //out << line;

        if (line == "#Jacked")
        {
            qDebug() << "line = #Jacked";
            //skip for now, unless we need to know the level number
            line = level.readLine();
        }
        /*
        else if (line == "#Obstacles")
        {
            int xPos;
            int yPos;
            QChar c;
            line = level.readLine();

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
        //*/
        else if (line == "#Player")
        {
            qDebug() << line;
            //Set the player's coordinates and weapon
            int xPos;
            int yPos;
            QChar c;
            QString weapon;
            line = level.readLine();
            //Skipping a line for some random reason
            line = level.readLine();

            for (int i = 0; i < line.length(); ++i)
            {
                if (line.at(0) == 'p')
                {
                    //the next thing is the x coordinate
                    xPos = line.at(9).digitValue();
                    yPos = line.at(11).digitValue();
                }
                else if (line.at(0) == 'w')
                {
                    for (int ind = i; ind < line.length(); ind++)
                    {
                        weapon += line.at(ind);
                    }
                }
                /*else if (c == ',')
                {
                    //the next thing is the y coordinate
                    qDebug() << "C is " << c << " and c + 1 is " << line.at(i + 1);
                    yPos = line.at(i).digitValue();
                    qDebug() << yPos;
                }*/
            }
            qDebug() << "x coordinate" << xPos;
            qDebug() << "y coordinate" << yPos;
            qDebug() << weapon;
            Player *player = new Player(xPos, yPos, new Weapon(weapon));
            //line = level.readLine();
        }
        else if (line == "#Enemies")
        {
            qDebug() << line;
            //set up the world's enemies
            int xPos;
            int yPos;
            int type;
            QChar c;
            QString weapon;
            line = level.readLine();
            //In here, get the object name that is supposed to be created - maybe we can have $type in the file?
            //line = level.readLine();
            for (int i = 0; i < line.length(); ++i)
            {
                if (line.at(0) == 'p')
                {
                    //the next thing is the x coordinate
                    xPos = line.at(9).digitValue();
                    yPos = line.at(11).digitValue();
                }

                else if (line.at(0) == 'w')
                {
                    for (int ind = i; ind < line.length(); ind++)
                    {
                        weapon += line.at(ind);
                    }
                }
                /*else if (c == ',')
                {
                    //the next thing is the y coordinate
                    yPos = line.at(i).digitValue();
                }

                else if (line.at(0) == '$')
                {
                    type = line.at(1).digitValue();
                }
                */
            }
            qDebug() << "x coordinate" << xPos;
            qDebug() << "y coordinate" << yPos;
            qDebug() << "enemy type = " << type;
            qDebug() << "weapon type = " << weapon;
            enemies.push_back(new Enemy(xPos, yPos, new Weapon(weapon)));
            //line = level.readLine();
        } else
        {
            line = level.readLine();
        }

    }
}

/*
//advances map to next lvl;
void Map::advance() {
    lvl++;
    //create();
}
*/
