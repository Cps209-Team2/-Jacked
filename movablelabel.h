#ifndef MOVABLELABEL_H
#define MOVABLELABEL_H
#include <Qt>
#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>

class MovableLabel:public QLabel
{

    Q_OBJECT

    QPoint offset;

public:
    explicit MovableLabel(QMainWindow *parent): QLabel(parent){ /* enable mouse move events */ }

    void keyPressEvent(QEvent *event){ qDebug() << "test" << endl; }

signals:
    void keyPressed();

};

#endif // MOVABLELABEL_H
