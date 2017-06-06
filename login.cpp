#include "login.h"
#include "ui_login.h"
#include "addpeople.h"
#include "dataStruct.h"
#include "functions.h"
#include <QMessageBox>
#include <cstdio>

int timeCounter;

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint |Qt::WindowSystemMenuHint|Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint);
    loadTime();	//加载时间
    loadBook();	//加载书籍信息
    loadPeople();	//加载人物信息
    WarnAlert();	//加载提醒事项
    saveBook(0);	//提醒事项会改变书籍人物信息，存储
    savePeople(0);	//存储
    ui->date->setText(QString("%1.%2.%3").arg(QString::number(date->year,10)).arg(QString::number(date->month,10)).arg(QString::number(date->day,10)));
    begin=startTimer(1000);
    timeCounter=0;
}

login::~login()
{
    delete ui;
}

void login::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==begin&&!stopTimer)
    {
        timeCounter++;
        if(5==timeCounter)
        {
            oneDayNewBook=1;
            dateCalculator();
            ui->date->setText(QString("%1.%2.%3").arg(QString::number(date->year,10)).arg(QString::number(date->month,10)).arg(QString::number(date->day,10)));
            WarnAlert();
            saveBook(0);
            savePeople(0);
            timeCounter=0;
        }
    }
}

void login::on_exit_clicked()
{
    saveBook(1);
    savePeople(1);
    saveTime();
    reject();
}

void login::on_register_2_clicked()
{
    stopTimer=1;
    timeCounter=0;
    theUser=reader;
    addPeople a;
    if(Accepted==a.exec())
        savePeople(0);
    stopTimer=0;
}

void login::on_enter_clicked()
{
    if(administrator->username==ui->userName->text()&&administrator->password==ui->password->text())
    {
        timeCounter=0;
        stopTimer=1;
        theUser=admini;
        ui->userName->clear();
        ui->password->clear();
        ui->userName->setFocus();
        keepDiary(NULL,NULL,loginP);
        accept();
    }
    else
    {
        personNode ppointer=peopleHead->nextPerson;
        while(ppointer)
        {
            if(QString::number(ppointer->id,10)==ui->userName->text())
            {
                if(ppointer->password==ui->password->text())
                {
                    timeCounter=0;
                    stopTimer=1;
                    ui->userName->clear();
                    ui->password->clear();
                    ui->userName->setFocus();
                    theUser=reader;
                    attentionP=ppointer;
                    keepDiary(attentionP,NULL,loginP);
                    accept();
                    break;
                }
                else
                {
                    QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("密码错误！"),QMessageBox::Yes);
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
            QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("用户名错误！"),QMessageBox::Yes);
            ui->userName->clear();
            ui->password->clear();
            ui->userName->setFocus();
        }
    }
}
