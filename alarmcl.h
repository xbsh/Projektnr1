#ifndef ALARMCL_H
#define ALARMCL_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class alarmcl;
}

class alarmcl : public QDialog
{
    Q_OBJECT

public:
    explicit alarmcl(QWidget *parent = nullptr);
    ~alarmcl();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::alarmcl *ui;
    QMainWindow *m;
};

#endif // ALARMCL_H
