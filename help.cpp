#include <QMainWindow>
#include "help.h"
#include "ui_help.h"
#include "startwindow.h"

help::help(QMainWindow *initParent) : QWidget(initParent),
    ui(new Ui::help)
{
    parent = initParent;
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_pbDone_clicked()
{
    emit helpClosed();
    this->close();

}
