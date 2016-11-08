#include "gamewindow.h"
#include "startwindow.h"
#include "world.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <cassert>
#include <QDebug>
#include <QString>
#include "obstacle.h"
#include "save.h"

void unitTests();

int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv + argc);

    if (args.size() > 1)
    {
        if (args.at(1) == "-test")
        {
            unitTests();
        }
    }


    QApplication a(argc, argv);
    StartWindow w;

    w.show();

    return a.exec();

}

void unitTests()
{
    std::cout << "Entering Unit Tests" << std::endl;
    World *testMap = World::instance();

    Weapon *item = new Weapon(QString::fromLocal8Bit("fist"));
    Player *mydude = new Player(45,45,item);
    qDebug() << "player created" << endl;
    Enemy *whataposer = new Enemy(85,45,item, mydude);
    qDebug() << "enemy created" << endl;
    //Obstacle *rock = new Obstacle(65,45);
    //qDebug() << "obstacle created" << endl;

    assert(item->getType() == QString::fromLocal8Bit("fist"));//weapon type

    assert(mydude->getPos().x() == 45);//player position
    assert(mydude->getPos().y() == 45);

    assert(whataposer->getPos().x() == 85);//enemy position
    assert(whataposer->getPos().y() == 45);

    //assert(rock->getPos().x() == 65);//obstacle position
    //assert(rock->getPos().y() == 45);

    assert(mydude->getWeapon()->getType() == QString::fromLocal8Bit("fist"));//assert that weapons are properly set on entities
    assert(whataposer->getWeapon()->getType() == QString::fromLocal8Bit("fist"));
    qDebug() << "Loading File";
    testMap->loadFile(QString::fromLocal8Bit(":/Levels/lvl1"));
    qDebug() << "File loaded";


    assert(testMap->getPlayer().getPos().x() == 0);
    assert(testMap->getPlayer().getPos().y() == 0);
    assert(testMap->getPlayer().getWeapon()->getType() == "fist");
    Enemy *testEnemy = dynamic_cast<Enemy*>(testMap->getEnemies().at(1));

    assert(testEnemy->getPos().x() == 200);
    assert(testEnemy->getPos().y() == 600);
    assert(testEnemy->getWeapon()->getType() == "fist");

    qDebug() << "Weapon is indeed fist";
    qDebug() << testMap->getPlayer().getWeapon()->getType();
    qDebug() << "Creating Player";

    testMap->getPlayer().setName(QString::fromLocal8Bit("Bert"));
    qDebug() << "Created Player, creating save";
    Save *save = new Save("SAVESCORE.txt", "SAVEWORLD.txt");

    testMap->getPlayer().setName(QString::fromLocal8Bit("JimBob"));
    qDebug() << "Saving Score and Map";
    save->saveScore(testMap);
    qDebug() << "Saved Score, starting to save map";
    save->saveWorld(testMap);
    qDebug() << "Finished saving";
    exit(0);
}
