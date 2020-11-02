#ifndef CHECKDREAM_H
#define CHECKDREAM_H

#include <QDialog>
//#include <QtSql>
//#include<QSqlDatabse>
namespace Ui {
class checkdream;
}

class checkdream : public QDialog
{
    Q_OBJECT

public:
    explicit checkdream(QWidget *parent = nullptr);
    ~checkdream();

private slots:
    void on_pushButton_clicked();

private:
    Ui::checkdream *ui;
};

#endif // CHECKDREAM_H
