#ifndef CHECKSQL_H
#define CHECKSQL_H
#include <QtSql>
#include<QSqlDatabase>
#include <QDialog>
#include "mainwindow.h"
#include "alarmcl.h"
namespace Ui {
class checksql;
}

class checksql : public QDialog
{
    Q_OBJECT

public:
    explicit checksql(QWidget *parent = nullptr);
    ~checksql();
    QSqlDatabase db;
    void dbClose()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}
    bool connOpen(){
        QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("dawajbyku");
        if(!db.open())
        {
          qDebug()<<"Nie mozna otworzyc bazy";
          return false;
        }
        else {qDebug()<<"polaczono z baza"; return true;}


    }

private slots:
    void on_pushButton_clicked();

    void on_historia_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::checksql *ui;
    QMainWindow *m;
    QSqlQueryModel *querymodel;

};

#endif // CHECKSQL_H
