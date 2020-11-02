#include "historia.h"
#include "ui_historia.h"
#include<QSqlDatabase>
#include <QtSql>
historia::historia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historia)
{
    ui->setupUi(this);
}
connOpen();
QSqlQueryModel * modal=new QSqlQueryModel();

historia::~historia()
{
    delete ui;
}
