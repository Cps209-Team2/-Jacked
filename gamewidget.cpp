#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QPixmap>
#include <QMainWindow>

gameWidget::gameWidget(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::gameWidget)
{
    this->setParent(parent);
    ui->setupUi(this);
}

gameWidget::~gameWidget()
{
    delete ui;
}
