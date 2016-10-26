#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QPixmap>
#include <QMainWindow>
#include <QTimer>
#include <QDebug>

gameWidget::gameWidget(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::gameWidget)
{
    test = 0;
    this->setParent(parent);
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(frame()));
    timer->setInterval(40);
    timer->start();
}

void gameWidget::frame()
{
    test++;
    qDebug() << test << endl;
}

gameWidget::~gameWidget()
{
    timer->stop();
    delete ui;
}
