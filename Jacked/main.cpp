#include "gamewindow.h"
#include <QApplication>
#include <iostream>
#include <vector>

void unitTests();

int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv + argc);

    if (args.size() > 1)
    {
        if (args.at(1) == "-r" || args.at(1) == "-R")
        {
            unitTests();
        }
    }
    QApplication a(argc, argv);
    GameWindow w;
    w.show();

    return a.exec();
}

void unitTests()
{
    std::cout << "Entering Unit Tests";
}
