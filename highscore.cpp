#include "highscore.h"

//constructs a highscores objects from the text file.
highscore::highscore() {
    QFile file("Highscores.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
       qDebug() << "File could not open." << endl;
    }
    qDebug() << "FIle is open" << endl;

    while(!file.atEnd()) {
        cout << "Inside loop" << endl;
        QString line = file.readLine();
        QStringList list = line.split(":");
        names.push_back(list.at(0).toStdString());
        scores.push_back(list.at(1).toInt());
    }
    qDebug() << "File is read" << endl;
    file.close();
    qDebug() << "FIle is closed" << endl;

}

//adds a highscore to the vector
void highscore::addHighScore(int highScore)
{
    scores.push_back(highScore);
    //highScores.erase(highScores.end());
}

//adds a name to the vector
void highscore::addName(string name)
{
    names.push_back(name);
}
