#ifndef SAVE_H
#define SAVE_H

#include <QString>
#include <QFile>
#include "map.h"

class Save
{
    QString filename;
public:
    Save(QString initFilename): filename(initFilename) {};
    void saveScore(Map& map);
    void saveWorld();
};

#endif // SAVE_H
