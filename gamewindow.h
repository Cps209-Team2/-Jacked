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

<<<<<<< HEAD
private slots:
    void keyPressEvent(QEvent * event);
=======

>>>>>>> 180a53dd2c833c260ded58229cdbcfca22447b5e
};

#endif // GAMEWINDOW_H
