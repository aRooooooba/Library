#include "peopledeatail.h"
#include "ui_peopledetail.h"
#include "dataStruct.h"
#include "editPassword.h"
#include "savePeople.h"
#include <QMessageBox>

extern personNode peopleHead,peopleTail,attentionP;
extern bookNode bookHead,bookTail;
extern int teacher,student,theUser,reader,administrator;

PeopleDetail::PeopleDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PeopleDetail)
{
    ui->setupUi(this);
    QPushButton * detailB[4],* returnB[4],* detailR[4];
    QLabel * bbID[4],* rbID[4];
    detailB[0]=ui->datailB1;
    detailB[1]=ui->detailB2;
    detailB[2]=ui->detailB3;
    detailB[3]=ui->detailB4;
    detailR[0]=ui->datailR1;
    detailR[1]=ui->detailR2;
    detailR[2]=ui->detailR3;
    detailR[3]=ui->detailR4;
    returnB[0]=ui->returnB1;
    returnB[1]=ui->returnB2;
    returnB[2]=ui->returnB3;
    returnB[3]=ui->returnB4;
    bbID[0]=ui->bbID1;
    bbID[1]=ui->bbID2;
    bbID[2]=ui->bbID3;
    bbID[3]=ui->bbID4;
    rbID[0]=ui->rbID1;
    rbID[1]=ui->rbID2;
    rbID[2]=ui->rbID3;
    rbID[3]=ui->rbID4;
    ui->name->setText(QString::fromLocal8Bit(attentionP->name));
    if(teacher==attentionP->job)
    {
        ui->job->setText(QString::fromLocal8Bit("教师"));
        ui->academy->setText(QString::fromLocal8Bit("无"));
    }
    else
    {
        ui->job->setText(QString::fromLocal8Bit("学生"));
        ui->academy->setText(QString::fromLocal8Bit(attentionP->academy));
    }
    ui->id->setText(QString::number(attentionP->id,10));
    ui->password->setText(QString::fromLocal8Bit(attentionP->password));
    ui->credit->setText(QString::number(attentionP->credit,10));
    ui->borrowNumber->setText(QString::number(attentionP->borrowNumber,10));
    for(int i=3;i>=attentionP->borrowNumber;i--)
    {
        bbID[i]->setVisible(false);
        detailB[i]->setVisible(false);
        returnB[i]->setVisible(false);
    }
    if(0<attentionP->borrowNumber)
    {
        borrowedBookNode bpointer=attentionP->bookBorrowed->nextBB;
        for(int i=0;i<attentionP->borrowNumber;i++,bpointer=bpointer->nextBB)
            bbID[i]->setText(QString::fromLocal8Bit(bpointer->id));
    }
    ui->reserveNumber->setText(QString::number(attentionP->reserveNumber,10));
    for(int i=3;i>=attentionP->reserveNumber;i--)
    {
        rbID[i]->setVisible(false);
        detailR[i]->setVisible(false);
    }
    if(0<attentionP->reserveNumber)
    {
        borrowedBookNode bpointer=attentionP->bookReserved->nextBB;
        for(int i=0;i<attentionP->reserveNumber;i++,bpointer=bpointer->nextBB)
            rbID[i]->setText(QString::fromLocal8Bit(bpointer->id));
    }
}

MyInformation::~MyInformation()
{
    delete ui;
}

void MyInformation::on_editPassword_clicked()
{
    Editpassword e;
    if(e.exec()==QDialog::Accepted)
        savePeople(0);
}
