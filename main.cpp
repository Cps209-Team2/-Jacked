#include "gamewindow.h"
#include "startwindow.h"
#include "map.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <cassert>

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


    //window.show();

    return a.exec();
}

void unitTests()
{
    std::cout << "Entering Unit Tests" << std::endl;
    //Map::loadFile(":/Levels/DefaultLevels/lvl1.txt");
    Map testMap;
    testMap.loadFile("../DefaultLevels/lvl1.txt");
    //Map testMap;
    //testMap.create();

}
