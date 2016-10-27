#include "gamewindow.h"
#include "startwindow.h"
#include "map.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <cassert>
#include <QDebug>

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
    Map testMap;

    testMap.loadFile(QString::fromLocal8Bit(":/Levels/lvl1"));

    qDebug() << "X Pos from testMap" << testMap.getPlayer().getPos().x();
    //assert(testMap.getPlayer().getPos().x() == 0);
    //assert(testMap.getPlayer().getPos().y() == 0);
}
