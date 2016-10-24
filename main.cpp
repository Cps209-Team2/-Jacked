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
    GameWindow window;
    window.show();
    StartWindow w;
    w.show();

    return a.exec();
}

void unitTests()
{
    std::cout << "Entering Unit Tests" << std::endl;
    Map testMap;
    testMap.create();

}
