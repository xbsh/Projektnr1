#ifndef HISTORIA_H
#define HISTORIA_H

#include <QDialog>
#include <QtSql>
#include<QSqlDatabase>


namespace Ui {
class historia;
}

class historia : public QDialog
{
    Q_OBJECT

public:
    explicit historia(QWidget *parent = nullptr);
    ~historia();
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


private:
    Ui::historia *ui;
};

#endif // HISTORIA_H
