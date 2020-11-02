#include "table.h"
#include "ui_table.h"

table::table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
}

table::~table()
{
    delete ui;
}
connOpen();
querymodel= new QSqlQueryModel;
querymodel->setQuery("SELECT * from dane");
QTableView *view = new QTableView;
view->setModel(querymodel);
view->show();
dbClose();
