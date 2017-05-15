#include "addbook.h"
#include "ui_addbook.h"

addBook::addBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBook)
{
    ui->setupUi(this);
    this->setFixedSize(435,716);
}

addBook::~addBook()
{
    delete ui;
}
