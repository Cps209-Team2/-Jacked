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

    //testing loadfile
    World& testMap = World::instance();

    testMap.loadFile(QString::fromLocal8Bit(":/Levels/lvl1"));
    qDebug() << "File loaded";


    assert(testMap.getPlayer().getPos().x() == 0);
    assert(testMap.getPlayer().getPos().y() == 600);
    assert(testMap.getPlayer().getWeapon()->getType() == "fist");
    Enemy *testEnemy = dynamic_cast<Enemy*>(testMap.getEnemies().at(1));

    assert(testEnemy->getPos().x() == 550);
    assert(testEnemy->getPos().y() == 600);
    assert(testEnemy->getWeapon()->getType() == "fist");

    qDebug() << "Weapon is indeed fist";
    qDebug() << testMap.getPlayer().getWeapon()->getType();
    qDebug() << "Creating Player";

    testMap.getPlayer().setName(QString::fromLocal8Bit("Bert"));
    qDebug() << "Created Player, creating save";
    Save *save = new Save("SAVESCORE.txt", "SAVEWORLD.txt");

    testMap.getPlayer().setName(QString::fromLocal8Bit("JimBob"));
    qDebug() << "Saving Score and Map";
    save->saveScore(testMap);
    qDebug() << "Saved Score, starting to save map";
    //save->saveWorld(testMap);
    qDebug() << "Finished saving";
    std::cout <<"All unit tests passed" << endl;
    exit(0);
}
