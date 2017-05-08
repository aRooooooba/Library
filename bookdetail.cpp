#include "bookdetail.h"
#include "ui_bookdetail.h"
#include "dataStruct.h"

extern bookNode attentionB;
extern int theUser,reader,administrator,MAXRNUM,teacher,student;

BookDetail::BookDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookDetail)
{
    ui->setupUi(this);
    QLabel * reserver[3];
    int i;
    reserver[0]=ui->reserver1;
    reserver[1]=ui->reserver2;
    reserver[2]=ui->reserver3;
    if(reader==theUser)
    {
        ui->editLimit->setVisible(false);
        ui->borrower->setText("******");
        ui->peopleDetail->setVisible(false);
        ui->reserver1->setVisible(false);
        ui->reserver2->setVisible(false);
        ui->reserver3->setVisible(false);
    }
    else
        ui->borrower->setText(QString::number(attentionB->borrower,10));
    ui->name->setText(QString::fromLocal8Bit(attentionB->name));
    ui->id->setText(QString::fromLocal8Bit(attentionB->id));
    ui->author->setText(QString::fromLocal8Bit(attentionB->author));
    ui->publisher->setText(QString::fromLocal8Bit(attentionB->publisher));
    ui->boughtTime->setText(QString("%1.%2.%3").arg(attentionB->boughtTime[0]).arg(attentionB->boughtTime[1]).arg(attentionB->boughtTime[2]));
    ui->number->setText(QString::number(attentionB->number,10));
    ui->description->setText(QString::fromLocal8Bit(attentionB->description));
    if(teacher==attentionB->limit)
        ui->limit->setText(QString::fromLocal8Bit("只有教师可借"));
    else
        ui->limit->setText(QString::fromLocal8Bit("所有人均可借"));
    if(0==attentionB->isBorrowed)
    {
        ui->borrower->setText(QString::fromLocal8Bit("无"));
        ui->peopleDetail->setVisible(false);
    }
    if(0==attentionB->reserveNumber)
        for(i=0;i<3;i++)
            reserver[i]->setVisible(false);
    for(i=0;i<attentionB->reserveNumber;i++)
        reserver[i]->setText(QString::number(attentionB->reserveQueue.base[(attentionB->reserveQueue.front+i)%MAXRNUM],10));
    for(;i<3;i++)
    {
        ui->more->setVisible(false);
        reserver[i]->setVisible(false);
    }
}

BookDetail::~BookDetail()
{
    delete ui;
}
