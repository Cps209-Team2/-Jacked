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
    explicit MovableLabel(QMainWindow *parent): QLabel(parent){ connect(this, SIGNAL(keyPressed()), this, SLOT(keyPressEvent())); }

private slots:
    void keyPressEvent(QEvent *event){ qDebug() << "test" << endl; }

signals:
    void keyPressed();

};

#endif // MOVABLELABEL_H
