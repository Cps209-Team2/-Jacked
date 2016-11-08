#include <QMainWindow>
#include "help.h"
#include "ui_help.h"
#include "startwindow.h"

help::help(QMainWindow *initParent) : QWidget(initParent),
    ui(new Ui::help)
{
    parent = dynamic_cast<StartWindow *>(initParent)->getStart();
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_pbDone_clicked()
{
    parent->show();
    parent->setFocus();
    emit destroyed();
    this->close();

}
