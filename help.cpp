#include <QMainWindow>
#include "help.h"
#include "ui_help.h"
#include "startwindow.h"

help::help(QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_pbDone_clicked()
{
    this->hide();
    //Ui::StartWindow::show();
    //StartWindow::show();

}
