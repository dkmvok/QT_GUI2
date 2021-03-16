#include "customerinfo.h"
#include "ui_customerinfo.h"

CustomerInfo::CustomerInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerInfo)
{
    ui->setupUi(this);
    Login conn;

            if(!conn.connectionOpen()){
               // qDebug()<<"Failed to open database";
                ui->label_Second_status->setText("Failed to open database");
            }
            else{
                // qDebug()<<"Conneted to database";
                 ui->label_Second_status->setText("Conneted to database");
            }
}

CustomerInfo::~CustomerInfo()
{
    delete ui;
}


void CustomerInfo::on_pushButton_clicked()
{

}
