#include "escmenu.h"
#include "ui_escmenu.h"
#include "save.h"
#include "map.h"
#include <QString>

EscMenu::EscMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EscMenu)
{
    ui->setupUi(this);
}

EscMenu::~EscMenu()
{
    delete ui;
}

void EscMenu::on_btnSave_clicked()
{
    Map *map = new Map();
    Save *save = new Save(QString::fromLocal8Bit("save.jkd"));
    save->saveScore(*map);
    //save->saveWorld();
    delete save;
}
