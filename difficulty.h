#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <QWidget>

namespace Ui {
class Difficulty;
}

class Difficulty : public QWidget
{
    Q_OBJECT

public:
    explicit Difficulty(QWidget *parent = 0);
    ~Difficulty();

private slots:
    void on_pbEasy_clicked();

    void on_pbMedium_clicked();

    void on_pbHard_clicked();

private:
    Ui::Difficulty *ui;
};

#endif // DIFFICULTY_H
