#ifndef ESCMENU_H
#define ESCMENU_H

#include <QWidget>

namespace Ui {
class EscMenu;
}

class EscMenu : public QWidget
{
    Q_OBJECT

public:
    explicit EscMenu(QWidget *parent = 0);
    ~EscMenu();

private slots:
    void on_btnSave_clicked();

private:
    Ui::EscMenu *ui;
};

#endif // ESCMENU_H
