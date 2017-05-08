#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataStruct.h"
#include "editPassword.h"
#include "savePeople.h"
#include "saveBook.h"
#include "peopledetail.h"
#include "bookinformation.h"
#include "peopleinformation.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QTimer>

extern personNode attentionP,peopleHead;
extern bookNode attentionB;
extern int theUser,reader,administrator,year,month,day;

void dateCalculator();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(reader==theUser)
    {
        ui->model->setText(QString::fromLocal8Bit("读者模式"));
        ui->name->setText(QString::fromLocal8Bit(attentionP->name));
        ui->manageBook->setVisible(false);
        ui->managePeople->setVisible(false);
    }
    else if(administrator==theUser)
    {
        ui->model->setText(QString::fromLocal8Bit("管理员模式"));
        ui->name->setText(QString::fromLocal8Bit("管理员"));
        ui->borrowBook->setVisible(false);
        ui->returnBook->setVisible(false);
        ui->editPassword->setVisible(false);
        ui->myInformation->setVisible(false);
    }
    ui->date->setText(QString("%1.%2.%3").arg(QString::number(year,10)).arg(QString::number(month,10)).arg(QString::number(day,10)));
    begin=startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    killTimer(begin);
    int r=QMessageBox::question(this,tr("Warning"),QString::fromLocal8Bit("确定要退出吗？"),QMessageBox::Yes|QMessageBox::Default,QMessageBox::No|QMessageBox::Escape);
    if (r==QMessageBox::Yes)
    {
        savePeople(1);
        saveBook(1);
        event->accept();
    }
    else
    {
        event->ignore();
        begin=startTimer(1000);
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==begin)
        dateCalculator();
    ui->date->setText(QString("%1.%2.%3").arg(QString::number(year,10)).arg(QString::number(month,10)).arg(QString::number(day,10)));
}

void MainWindow::on_editPassword_clicked()
{
    killTimer(begin);
    Editpassword e;
    if(e.exec()==QDialog::Accepted)
        savePeople(0);
    begin=startTimer(1000);
}

void MainWindow::on_myInformation_clicked()
{
    killTimer(begin);
    PeopleDetail p;
    p.exec();
    begin=startTimer(1000);
}

void MainWindow::on_manageBook_clicked()
{
    killTimer(begin);
    BookInformation b;
    b.exec();
    begin=startTimer(1000);
}

void dateCalculator()
{
    day++;
    if(32==day&&(1==month||3==month||5==month||7==month||8==month||10==month||12==month))
    {
        month++;
        if(12==month)
        {
            month=1;
            year++;
        }
        day=1;
    }
    else if(31==day&&(4==month||6==month||9==month||11==month))
    {
        month++;
        day=1;
    }
    else if(2==month)
    {
        if(30==day&&((0==year%4&&0!=year%100)||0==year%400))
        {
            month++;
            day=1;
        }
        else if(29==day)
        {
            month++;
            day=1;
        }
    }
}

void MainWindow::on_managePeople_clicked()
{
    killTimer(begin);
    PeopleInformation p;
    p.exec();
    begin=startTimer(1000);
}
