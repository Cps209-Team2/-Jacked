#include <fstream>
#include <QMessageBox>
#include <iterator>
#include "world.h"
#include "entity.h"
#include "enemy.h"
#include <QDebug>
#include "player.h"
#include "obstacle.h"

using namespace std;

World *World::instance_ = new World();

World &World::instance() {
    if (instance_ == nullptr) {
        instance_ = new World();
    }
    return *instance_;
}
//Singleton implementation

void World::addEntity(Entity *obj)
{
    if(dynamic_cast<Player *>(obj) != nullptr)
    {
        player = dynamic_cast<Player*>(obj);
    }
    if(dynamic_cast<Enemy *>(obj) != nullptr)
    {
        enemies.push_back(dynamic_cast<Enemy*>(obj));
    }
}

void World::trash(int ID)
{
    for(size_t i = 0; i < enemies.size(); i++)
    {
        if(enemies.at(i)->getId() == ID)
        {
            trashbin.push_back(dynamic_cast<Enemy*>(enemies.at(i)));
            enemies.erase(enemies.begin() + i);
        }
    }
}


//loads saved or default map
void World::loadFile(QString filename) {

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
    qDebug() << level;

    processLevel(level);
    inFile.close();
}

// Puts all the game variables into the correct vector
void World::processLevel(QString levels)
{
    QTextStream level(&levels);
    QString line;
    QString levelStr;
    while (line != "*")
    {
        line = level.readLine();
        if (line == "*")
        {
            break;
        }

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
            Player *player = new Player(xPos, yPos, new Weapon(weapon));
            this->addEntity(player);
            qDebug() << "created player" << endl;
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
                Enemy *enemy = new Enemy(xPos, yPos, new Weapon(weapon),this->player, rand() % 5 + 1);
                this->addEntity(enemy);
                qDebug() << "created enemy" << endl;
            }
        }
        qDebug() << "finished" << endl;
    }
}


World::~World()
{
    delete this->player;

    for(Enemy *i : enemies)
    {
        delete i;
    }
    for(Obstacle *i : obstacles)
    {
        delete i;
    }
    for(Enemy *i : trashbin)
    {
        delete i;
    }
}

static void saveScore()
{

}
