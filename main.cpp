#include "gamewindow.h"
#include "startwindow.h"
#include "map.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <cassert>
#include <QDebug>
#include <QString>
#include "obstacle.h"

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
    Map& testMap = Map::instance();

    testMap.loadFile(QString::fromLocal8Bit(":/Levels/lvl1"));

    Weapon *item = new Weapon(QString::fromLocal8Bit("fist"));
    Player *mydude = new Player(45,45,item);
    Enemy *whataposer = new Enemy(85,45,item);
    Obstacle *rock = new Obstacle(65,45);

    assert(item->getType() == QString::fromLocal8Bit("fist"));//weapon type

    assert(mydude->getPos().x() == 45);//player position
    assert(mydude->getPos().y() == 45);

    assert(whataposer->getPos().x() == 85);//enemy position
    assert(whataposer->getPos().y() == 45);

    assert(rock->getPos().x() == 65);//obstacle position
    assert(rock->getPos().y() == 45);

    assert(mydude->getWeapon()->getType() == QString::fromLocal8Bit("fist"));//assert that weapons are properly set on entities
    assert(whataposer->getWeapon()->getType() == QString::fromLocal8Bit("fist"));

    testMap.loadFile(QString::fromLocal8Bit(":/Levels/lvl1"));

    qDebug() << "X Pos from testMap" << testMap.getPlayer().getPos().x();
    assert(testMap.getPlayer().getPos().x() == 0);
    assert(testMap.getPlayer().getPos().y() == 0);
}
