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

}

Map* Map::instance_ = nullptr;

Map& Map::instance() {
  if (instance_ == nullptr) {
      instance_ = new Map();
  }
  return *instance_;
}
//Singleton implementation

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
    QString section;
    QString levelStr;
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
            if (line.contains("level"))
            {
                levelStr = *(line.end() - 1);
                qDebug() << "Level = " << levelStr;
            }
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


            if (line.at(0) == 'p')
            {
                QStringList lineColon = line.split(':');
                QStringList positions = lineColon.at(1).split(',');
                xPos = positions.at(0).toInt();
                yPos = positions.at(1).toInt();

                line = level.readLine();
                lineColon = line.split(':');
                weapon = lineColon.at(1);
            }
            else
            {
                level.readLine();
            }

            qDebug() << "x coordinate" << xPos;
            qDebug() << "y coordinate" << yPos;
            qDebug() << weapon;
            Map::instance().setPlayer(new Player(xPos, yPos, new Weapon(weapon)));
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
            QString name;

            while (line != "*")
            {
                line = level.readLine();

                if (line.at(0) == '$')
                {
                    line = level.readLine();
                    QStringList lineColon = line.split(':');
                    QStringList positions = lineColon.at(1).split(',');

                    xPos = positions.at(0).toInt();
                    yPos = positions.at(1).toInt();
                    line = level.readLine();

                    lineColon = line.split(':');
                    weapon = lineColon.at(1);
                    line = level.readLine();
                }
                else
                {
                    line = level.readLine();
                }


                qDebug() << "x coordinate" << xPos;
                qDebug() << "y coordinate" << yPos;
                qDebug() << "weapon type = " << weapon;
<<<<<<< HEAD

                enemies.push_back(new Enemy(xPos, yPos, new Weapon(weapon),this->player));

                qDebug() << "next iteration" << endl;
=======
                //*/
                Enemy *poser = new Enemy(xPos, yPos, new Weapon(weapon));
                Map::instance().getEnemies().push_back(poser);
                //delete poser;
>>>>>>> 77fa67c0c69b0d67ccdc76877da7ac59ad02fb44
            }
        }
    }
}


Map::~Map()
{
    delete this->player;

    for(auto i : this->enemies)
    {
        delete i;
    }
    for(auto i : this->obstacles)
    {
        delete i;
    }
}

/*
//advances map to next lvl;
void Map::advance() {
    lvl++;
    //create();
}
*/
