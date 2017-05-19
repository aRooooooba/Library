#include "addpeople.h"
#include "ui_addpeople.h"
#include "dataStruct.h"
#include "functions.h"
#include <cstring>
#include <cstdlib>
#include <QInputDialog>
#include <QMessageBox>

personNode ppointer=NULL;

addPeople::addPeople(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPeople)
{
    ui->setupUi(this);
    this->setFixedSize(360,585);
    ppointer=(personNode)malloc(sizeof(person));
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
    ui->academy->clear();
    ui->academy->setEnabled(false);
}

void addPeople::on_cancel_clicked()
{
    free(ppointer);
    reject();
}

void addPeople::on_ensured_clicked()
{
    QByteArray T;
    char * C;
    if(ui->name->text().isEmpty())
    {
        ui->name->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请输入姓名！"),QMessageBox::Yes);
    }
    else if(ui->ID->text().isEmpty())
    {
        ui->ID->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请输入ID！"),QMessageBox::Yes);
    }
    else if(ui->password->text().isEmpty())
    {
        ui->password->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请输入密码！"),QMessageBox::Yes);
    }
    else if(ui->password_2->text().isEmpty())
    {
        ui->password->clear();
        ui->password_2->clear();
        ui->password->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请确认密码！"),QMessageBox::Yes);
    }
    else if(ui->student->isChecked()&&ui->academy->text().isEmpty())
    {
        ui->academy->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请填写学院信息！"),QMessageBox::Yes);
    }
    else if(!ui->student->isChecked()&&!ui->teacher->isChecked())
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请选择职业！"),QMessageBox::Yes);
    else if(ui->password->text()!=ui->password_2->text())
    {
        ui->password->clear();
        ui->password_2->clear();
        ui->password->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("两次密码不一致！"),QMessageBox::Yes);
    }
    else
    {
        T=ui->name->text().toLocal8Bit();
        C=T.data();
        strcpy(ppointer->name,appendEnter(C));
        ppointer->id=ui->ID->text().toInt();
        personNode ppointer1=peopleHead->nextPerson;
        for(;ppointer1&&ppointer1->id!=ppointer->id;ppointer1=ppointer1->nextPerson);
        if(ppointer1)
        {
            ui->ID->clear();
            ui->ID->setFocus();
            QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("已存在此ID！"),QMessageBox::Yes);
        }
        else
        {
            T=ui->password->text().toLocal8Bit();
            C=T.data();
            strcpy(ppointer->password,C);
            if(student==ppointer->job)
            {
                T=ui->academy->text().toLocal8Bit();
                C=T.data();
                strcpy(ppointer->academy,appendEnter(C));
            }
            ppointer->credit=100;
            ppointer->borrowNumber=0;
            ppointer->borrowedBTail=NULL;
            ppointer->reserveNumber=0;
            ppointer->reservedBTail=NULL;
            if(reader==theUser)
            {
                bool ok=false;
                QString ADKey=QInputDialog::getText(this,tr("Warning"),QString::fromLocal8Bit("请输入管理员密钥："),QLineEdit::Password,QString::null,&ok);
                if(ok&&!ADKey.isEmpty())
                {
                    T=ADKey.toLocal8Bit();
                    C=T.data();
                    if(0==strcmp("user",C))
                    {
                        peopleTail->nextPerson=ppointer;
                        peopleTail=ppointer;
                        accept();
                    }
                    else
                        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("管理员密钥错误！"),QMessageBox::Yes);
                }
            }
            else
            {
                peopleTail->nextPerson=ppointer;
                peopleTail=ppointer;
                ppointer=(personNode)malloc(sizeof(person));
                ppointer->nextPerson=NULL;
                if(QMessageBox::Yes==QMessageBox::question(this,tr("Question"),QString::fromLocal8Bit("是否继续添加？"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
                {
                    ui->name->clear();
                    ui->ID->clear();
                    ui->password->clear();
                    ui->password_2->clear();
                    ui->academy->clear();
                }
                else
                {
                    free(ppointer);
                    accept();
                }
            }
        }
    }
}
