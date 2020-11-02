#include "alarmcl.h"
#include "ui_alarmcl.h"
#include"mainwindow.h"
#include<QMessageBox>
#include<iostream>
#include <QTextStream>
#include <QTime>
#include <QDebug>
alarmcl::alarmcl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alarmcl)
{
    ui->setupUi(this);
}


alarmcl::~alarmcl()
{
    delete ui;
}

void alarmcl::on_pushButton_2_clicked()
{
  m=new MainWindow(this);
  m->show();
}

void alarmcl::on_pushButton_clicked()
{
   QDateTime sleep= ui->timeEdit->dateTime();
   QDateTime wakeup = ui->timeEdit_2->dateTime();
   QTime w=wakeup.time();
   QTime s=sleep.time();
   qint64 Diff = w.secsTo(s);
   int minutes= Diff/60;
   int finalwu;
   if(s>w)
   {
       QTime sleep1 = QTime::fromMSecsSinceStartOfDay(86399999); // Tutaj ustawiam na sztywny 24h w ms
       int sleepm = QTime(0, 0, 0).msecsTo(s); // wrzucam czas snu do inta
       sleepm=sleepm*-1;
       QTime final= sleep1.addMSecs(sleepm); //odejmuje 24-godz od inta zeby otrzymac roznice
       int slep1 = QTime(0 ,0 ,0).msecsTo(final); // wrzucam roznice w inta
       QTime polnosc = QTime(0,0,0).addMSecs(slep1); //przesuwam czas o roznice
       qint64 test= polnosc.msecsTo(w); // sprawdzam ile ms od pobudki do przesunietego czasu
       int diff = test+2*slep1; // to jest ostateczna roznica miedzy pojsciem spac a wstaniem
       int min=diff/60000;
            int pointer=115;// 15 minut na zasniecie 90minut na koniec cyklu możliwego budzenia
            while (pointer<min){pointer+=90;}
              if(pointer-min<=50)
                {
                QTime finaltime;
                finalwu=min;
                finaltime=w;
                QString prt=finaltime.toString("hh:mm");
                ui->lineEdit->setText("Ustaw alarm na: "+prt);
                }
             else {
                  finalwu=pointer-90;
                  int sToms=finalwu*60000;
                  QTime finaltime;
                  finaltime=s.addMSecs((int)sToms);
                  QString prt=finaltime.toString("hh:mm");
                  ui->lineEdit->setText("Ustaw alarm na: "+prt);
                  }
           qDebug()<<min;
           qDebug()<<finalwu;
   }
   else{
         if(minutes<0)
         {
             minutes=minutes*(-1);
             int pointer=115;// 15 minut na zasniecie 90minut na koniec cyklu możliwego budzenia
                while (pointer<minutes){pointer+=90;}
                 if(pointer-minutes<=50)
                    {
                      QTime finaltime;
                      finalwu=minutes;
                      finaltime=w;
                      QString prt=finaltime.toString("hh:mm");
                      ui->lineEdit->setText("Ustaw alarm na: "+prt);
                    }
                 else {
                        finalwu=pointer-90;
                        int sToms=finalwu*60000;
                        QTime finaltime;
                        finaltime=s.addMSecs((int)sToms);
                        QString prt=finaltime.toString("hh:mm");
                        ui->lineEdit->setText("Ustaw alarm na: "+prt);
                      }
                 qDebug()<<minutes;
                 qDebug()<<finalwu;
           }
      }

}

void alarmcl::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "policalc", "Kalkulator wylicza, o której ustawić budzik, aby obudzić się w fazie snu lekkiego. Wliczone jest 15 minut na zaśnięcie także nie trzeba tego uwzględniać \n \n Dlaczego czas ustawia się  na godzinę, którą ustawiłem? \n Bo akurat udało wpasować Ci się w fazę snu lekkiego.", QMessageBox::Ok);
}
