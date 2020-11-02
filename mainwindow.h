#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#include"alarmcl.h"
#include"checksql.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonBox_accepted();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    QPushButton *cancelButton;
    QPushButton *backButton;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

