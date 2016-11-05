#include "escmenu.h"
#include "ui_escmenu.h"
#include "save.h"
#include "world.h"
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
    World *world = new World();
    Save *save = new Save(QString::fromLocal8Bit("save.jkd"));
    save->saveScore(world);
    //save->saveWorld();
    delete save;
}
