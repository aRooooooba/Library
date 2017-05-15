#include "addpeople.h"
#include "ui_addpeople.h"

addPeople::addPeople(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPeople)
{
    ui->setupUi(this);
    this->setFixedSize(360,585);
}

addPeople::~addPeople()
{
    delete ui;
}
