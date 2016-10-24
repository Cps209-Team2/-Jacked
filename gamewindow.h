#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::GameWindow *ui;

private slots:
    void keyPressEvent(QEvent * event);
};

#endif // GAMEWINDOW_H
