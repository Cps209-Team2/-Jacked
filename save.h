#ifndef SAVE_H
#define SAVE_H

#include <QString>
#include <QFile>

class Save
{
    QString filename;
public:
    Save(QString initFilename): filename(initFilename) {};
    void saveScore();
    void saveWorld();
};

#endif // SAVE_H
