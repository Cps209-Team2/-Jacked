#ifndef MOVABLELABEL_H
#define MOVABLELABEL_H
#include <Qt>
#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>
#include <entity.h>

class MovableLabel:public QLabel
{

    Q_OBJECT

    QPoint offset;
    Entity *object;

public:
    explicit MovableLabel(QWidget *parent, Entity *obj): QLabel(parent)
    {
        object = obj;
    }
    void updatePos() { this->move(object->getPos()); }

private slots:
    void keyPressEvent(QEvent *event){ qDebug() << "test" << endl; }

signals:
    void keyPressed();

};

#endif // MOVABLELABEL_H
