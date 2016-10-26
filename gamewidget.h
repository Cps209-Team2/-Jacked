#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class gameWidget;
}

class gameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit gameWidget(QMainWindow *parent = 0);
    ~gameWidget();

private:
    Ui::gameWidget *ui;
    QTimer *timer;
    int test;
private slots:
    void frame();
};

#endif // GAMEWIDGET_H
