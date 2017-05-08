#include "editPassword.h"
#include "ui_editpassword.h"
#include "dataStruct.h"
#include <cstring>
#include <QMessageBox>

extern personNode attentionP,peopleHead,peopleTail;

Editpassword::Editpassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editpassword)
{
    ui->setupUi(this);
}

Editpassword::~Editpassword()
{
    delete ui;
}

void Editpassword::on_ensured_clicked()
{
    if(QString::fromStdString(attentionP->password) ==ui->oldPassword->text())
    {
        if(ui->newPassword->text()==ui->newPassword_2->text())
        {
            QByteArray qb=ui->newPassword->text().toLocal8Bit();
            char * c=qb.data();
            strcpy(attentionP->password,c);
            personNode ppointer=peopleHead->nextPerson;
            while(ppointer->id!=attentionP->id)
                ppointer=ppointer->nextPerson;
            strcpy(ppointer->password,c);
            QMessageBox::warning(this,tr("OK"),QString::fromLocal8Bit("修改成功！"),QMessageBox::Yes);
            accept();
        }
        else
        {
            QMessageBox::warning(this,tr("Error"),QString::fromLocal8Bit("两次新密码不一致！"),QMessageBox::Yes);
            ui->newPassword->clear();
            ui->newPassword_2->clear();
            ui->newPassword->setFocus();
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Error"),QString::fromLocal8Bit("原密码错误！"),QMessageBox::Yes);
        ui->oldPassword->clear();
        ui->newPassword->clear();
        ui->newPassword_2->clear();
        ui->oldPassword->setFocus();
    }
}
