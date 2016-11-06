#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class help;
}

class help : public QWidget
{
    Q_OBJECT
    QWidget *parent;

public:
    explicit help(QMainWindow *parent = 0);
    ~help();

private slots:
    void on_pbDone_clicked();
signals:
    void helpClosed();

private:
    Ui::help *ui;
};

#endif // HELP_H
