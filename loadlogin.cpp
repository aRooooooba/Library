#include "loadlogin.h"
#include "ui_loadlogin.h"
#include "dataStruct.h"
#include "loadBook.h"
#include "loadPeople.h"
#include "copyinfop.h"
#include <QMessageBox>
#include <QButtonGroup>
#include <cstring>
using namespace std;

extern personNode peopleHead,attentionP;
extern int theUser;

QButtonGroup * users;

void copyInfo1(personNode ppointer);

Loadlogin::Loadlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loadlogin)
{
    ui->setupUi(this);
    users=new QButtonGroup(this);
    users->addButton(ui->reader,0);
    users->addButton(ui->administrator,1);
    loadBook();
    loadPeople();
}

Loadlogin::~Loadlogin()
{
    delete users;
    delete ui;
}

void Loadlogin::on_enter_clicked()
{
    personNode ppointer=peopleHead->nextPerson;
    theUser=users->checkedId();
    switch(theUser)
    {
    case 0: //读者
        while(ppointer)
        {
            if(QString::number(ppointer->id,10)==ui->username->text())
            {
                if(ppointer->password==ui->password->text())
                {
                    copyInfoP(ppointer,attentionP);
                    accept();
                    break;
                }
                else
                {
                    QMessageBox::warning(this,tr("Error"),QString::fromLocal8Bit("密码错误！"),QMessageBox::Yes);
                    ui->password->clear();
                    ui->password->setFocus();
                    break;
                }
            }
            else
                ppointer=ppointer->nextPerson;
        }
        if(!ppointer)
        {
            QMessageBox::warning(this,tr("Error"),QString::fromLocal8Bit("用户名错误！"),QMessageBox::Yes);
            ui->username->clear();
            ui->password->clear();
            ui->username->setFocus();
        }
        break;
    case 1: //管理员
        if("user"==ui->username->text()&&"user"==ui->password->text())
            accept();
        else
        {
            QMessageBox::warning(this,tr("Error"),QString::fromLocal8Bit("用户名或密码错误！"),QMessageBox::Yes);
            ui->password->clear();
            ui->password->setFocus();
        }
        break;
    }
}
