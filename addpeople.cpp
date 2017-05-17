#include "addpeople.h"
#include "ui_addpeople.h"
#include "dataStruct.h"
#include "functions.h"

personNode ppointer=(personNode)malloc(sizeof(person));

addPeople::addPeople(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPeople)
{
    ui->setupUi(this);
    this->setFixedSize(360,585);
    ppointer->nextPerson=NULL;
}

addPeople::~addPeople()
{
    delete ui;
}

void addPeople::on_student_clicked()
{
    ppointer->job=student;
    ui->academy->setEnabled(true);
}

void addPeople::on_teacher_clicked()
{
    ppointer->job=teacher;
    ui->academy->setEnabled(false);
}

void addPeople::on_cancel_clicked()
{
    free(ppointer);
    reject();
}

void addPeople::on_ensured_clicked()
{

}
