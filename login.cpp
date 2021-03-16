#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    //QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
   // mydb.setDatabaseName("C:>Users/jar/DB/database.db");

    if(!connectionOpen()){
        qDebug()<<"Failed to open database";
        ui->label->setText("Failed to open database");
        return;
    }
    else{
         qDebug()<<"Conneted to database";
         ui->label->setText("Conneted to database");
    }

}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    QString username, password;
    username= ui->lineEdit_Username->text();
    password = ui->lineEdit_Password->text();

    if(!connectionOpen()){
        qDebug()<<"Failed to open database";
        //return;
    }

    connectionOpen();

    QSqlQuery query;
    query.prepare("select from customer username::'"+username+"' and password='"+password+"'");

   // if(query.exec("select from customer username:'"+username+"' and password='"+password+"'")){
    if(query.exec()){

        int count=0;
        while(query.next()){
            count++;
        }
        if(count == 1){
            qDebug()<<"Login successful";
            ui->label->setText("Login successful");
            connectionClose();

            this->hide();
            CustomerInfo customerinfo;
            customerinfo.setModal(true);
            customerinfo.exec();
        }
        if(count > 1)
            ui->label->setText("Login unsuccessful, User already exist. Please check password or username");
        if(count < 1)
            ui->label->setText("Login unsuccessful. Please check password or username");
    }
}

