#ifndef TABLE_H
#define TABLE_H
#include <QtSql>
#include<QSqlDatabase>
#include <QDialog>
#include <QDialog>

namespace Ui {
class table;
}

class table : public QDialog
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = nullptr);
    ~table();

private:
    Ui::table *ui;
};

#endif // TABLE_H
