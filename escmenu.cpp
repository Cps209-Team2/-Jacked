#include "escmenu.h"
#include "gamewidget.h"
#include "ui_escmenu.h"
#include "save.h"
#include "world.h"
#include <QString>

EscMenu::EscMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EscMenu)
{
    ui->setupUi(this);
    thisParent = parent;
}

EscMenu::~EscMenu()
{
    delete ui;
}

void EscMenu::on_btnSave_clicked()
{
    World& world = World::instance();
    Save *save = new Save(QString::fromLocal8Bit("saveScore.jkd"), QString::fromLocal8Bit("saveWorld.jkd"));
    save->saveScore(world);
    save->saveWorld(world);
    delete save;
}

void EscMenu::on_btnExit_clicked()
{

    QTimer *timer = dynamic_cast<gameWidget*>(thisParent)->getTimer();
    thisParent->setFocus();
    timer->start();
    this->close();

}
