#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include "customerinfo.h"


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase mydb;

    void connectionClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);

    }
    bool connectionOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/jar/DB/database.db");

        if(!mydb.open()){
            qDebug()<<"Failed to open database";
           // ui->label->setText("Failed to open database");
            return false;
        }
        else{
            qDebug()<<"Conneted to database";
             //ui->label->setText("Conneted to database");
        }
    }

public:
    Login(QWidget *parent = nullptr);
    ~Login();


private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    //QSqlDatabase mydb;
};
#endif // LOGIN_H
