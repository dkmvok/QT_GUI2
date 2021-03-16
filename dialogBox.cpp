#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"
#include "QDebug"

CheckOutDialog::CheckOutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckOutDialog)
{
    ui->setupUi(this);
    this->setFixedSize(320,180);

}

void CheckOutDialog::readData()
{
    std::vector<int>books = Library::getInstance()->getBookList("n");
    this->ui->entireRoomList->clear();
    char addFlag = 0;
    for(std::vector<int>::iterator it = books.begin(); it!=books.end(); it++ )
    {
        this->ui->entireBookList->addItem(QString::number(*it));
        addFlag = 1;
    }

    if(addFlag==1) this->ui->btnCheckout->setEnabled(true);

}

CheckOutDialog::~CheckOutDialog()
{
    delete ui;
}

void CheckOutDialog::on_btnCancel_clicked()
{
    this->hide();
}

void CheckOutDialog::on_btnCheckout_clicked()
{

    //book checkout
    int  bookNum = ui->entireRoomList->currentText().toInt();

    if(bookNum < 1)
    {
            QMessageBox::information(
            this,
            tr("Attention: Warning!"),
            tr("No book to Check out") );
            return;
     }
    int retVal = Library::getInstance()->CheckOut(bookNum);

    QString msg = "";
    retVal == 0?msg="Successful!":"Failure!";

    this->hide();

    if(retVal == 0)
    {
        QMessageBox::information(
        this,
        tr("Successful!"),
        tr("Book has been Check-out! Thank you") );
    }
}
