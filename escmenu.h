#ifndef ESCMENU_H
#define ESCMENU_H

#include <QWidget>
#include <QTimer>

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

    void on_btnExit_clicked();

private:
    Ui::EscMenu *ui;
    QTimer timer;
    QWidget *thisParent;
};

#endif // ESCMENU_H
