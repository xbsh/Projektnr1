#include "checkdream.h"
#include "ui_checkdream.h"
#include"checksql.h"
#include <QtSql>
#include<QSqlDatabase>
#include <QMessageBox>
checkdream::checkdream(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkdream)
{
    ui->setupUi(this);
}

checkdream::~checkdream()
{
    delete ui;
}

void checkdream::on_pushButton_clicked()
{

    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("qtsql");
        if(db.open())
        {
            checksql checksql;
            checksql.setModal(true);
            checksql.exec();
        }
        else
        {
               QMessageBox::information(this,"Brak polaczenia", "Nie udalo polaczyc sie z baza danych");
        }
}
