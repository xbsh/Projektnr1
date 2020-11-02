#include "checksql.h"
#include "ui_checksql.h"
#include <QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<iostream>
#include <QTextStream>
#include <QTime>
#include <QDebug>
#include<QTextEdit>
#include <QDialog>
#include <QPushButton>
#include"mainwindow.h"
checksql::checksql(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checksql)
{
    ui->setupUi(this);
}

checksql::~checksql()
{
    delete ui;
}

void checksql::on_pushButton_clicked()
{
        connOpen();
        QDateTime sleep= ui->timeEdit->dateTime();
        QDateTime wakeup = ui->timeEdit2->dateTime();
        QTime w=wakeup.time();
        QTime s=sleep.time();
        qint64 Diff = s.secsTo(w);
        int minutes= Diff/60*(-1);
        int spales=minutes;
        int ilosccykli=minutes/90;
        int fazarem=minutes-ilosccykli*90;
        int fazanrem=minutes-fazarem;
              QSqlQuery qry;
              qry.prepare("INSERT INTO dane(spales,ilosccykli,fazarem,fazanrem)""VALUES (:spales,:ilosccykli, :fazanrem, :fazarem)");
              qry.bindValue(":spales",spales);
              qry.bindValue(":ilosccykli",ilosccykli);
              qry.bindValue(":fazarem",fazarem);
              qry.bindValue(":fazanrem",fazanrem);
              if(qry.exec()){qDebug()<<"dodano dane do bazy";}else{qDebug()<<"nie udalo sie dodac danych do bazy";}
                    QString spalestr= QString::number(spales);
                    QString iloscstr= QString::number(ilosccykli);
                    QString remstr= QString::number(fazarem);
                    QString nremstr= QString::number(fazanrem);
                       ui->iloscminut->setText("Spaleś: " + spalestr +"minut");
                       ui->ilosccykli->setText("Ilość faz snu: " +iloscstr);
                       ui->fazanrem->setText("Ilość minut w fazie nrem: " +nremstr);
                       ui->fazarem->setText("Ilość  minut w fazie rem: " +remstr);
                       if (spales>=360 && spales<=600)
                        {
                         ui->spisz->setText("Śpisz wystarczającą ilość godzin");
                        }
                       else if (spales>600){ ui->spisz->setText("Śpisz za dużo");}
                       else{ ui->spisz->setText("Śpisz za mało godzin");}
           dbClose();

}

void checksql::on_historia_clicked()
{
    connOpen();
    this->hide();
    QSqlQueryModel* modal=new QSqlQueryModel();
    QSqlQuery * qry= new QSqlQuery(db);
    qry->prepare("SELECT * FROM dane");
    qry->exec();
    modal->setQuery(*qry);
     QTableView *view = new QTableView;
        view->setModel(modal);
            view->show();
    dbClose();
}

void checksql::on_pushButton_3_clicked()
{
    m=new MainWindow(this);
    m->show();
}
