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
    QTimer *timer = dynamic_cast<gameWidget*>(thisParent)->getTimer();
    thisParent->setFocus();
    timer->start();
    this->close();
}

void EscMenu::on_btnSave_clicked()
{
    World& world = World::instance();
    Save *save = new Save(QString::fromLocal8Bit("Score.jkd"), QString::fromLocal8Bit("World.jkd"));
    save->saveScore(world);
    save->saveWorld(world);
    delete save;
}

void EscMenu::on_btnExit_clicked()
{
    QTimer *timer = dynamic_cast<gameWidget*>(thisParent)->getTimer();
    thisParent->setFocus();
    timer->start();
    this->hide();
    this->close();
}

void EscMenu::on_btnLoad_clicked()
{
    gameWidget *game = dynamic_cast<gameWidget*>(thisParent);
    World::instance().loadFile("World.jkd");
    game->reset();
}
