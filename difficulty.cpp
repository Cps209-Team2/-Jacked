#include "difficulty.h"
#include "ui_difficulty.h"

Difficulty::Difficulty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Difficulty)
{
    ui->setupUi(this);
}

Difficulty::~Difficulty()
{
    delete ui;
}

void Difficulty::on_pbEasy_clicked()
{
    //load lvl1.txt
}
void Difficulty::on_pbMedium_clicked()
{
    //load lvl2.txt
}

void Difficulty::on_pbHard_clicked()
{
    //load lvl3.txt
}
