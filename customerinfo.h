#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H

#include <QDialog>
#include "login.h"

namespace Ui {
class CustomerInfo;
}

class CustomerInfo : public QDialog
{
    Q_OBJECT

public:
    //Mainwindow conn;
    explicit CustomerInfo(QWidget *parent = nullptr);
    ~CustomerInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CustomerInfo *ui;
};

#endif // CUSTOMERINFO_H
