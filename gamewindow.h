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
    void keyPressEvent(QEvent *event);
    void keyPressEvent();
    ~GameWindow();

signals:
    void key_PressEvent(QEvent *event);

private:
    Ui::GameWindow *ui;

private slots:
    void key_pressed(QEvent * event);
};

#endif // GAMEWINDOW_H
