#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonBox_accepted()
{
    if(ui->radioButton->isChecked())
    {
        this->hide();
        alarmcl alarmcl;
        alarmcl.setModal(true);
        alarmcl.exec();
    }
    else if(ui->radioButton_2->isChecked())
    {
        this->hide();
        checksql checksql;
        checksql.exec();
    }
}

void MainWindow::on_radioButton_clicked()
{

}

void MainWindow::on_radioButton_2_clicked()
{

}
