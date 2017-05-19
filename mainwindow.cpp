#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataStruct.h"
#include "functions.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeUI();
}

void MainWindow::initializeUI()
{
    //this->setFixedSize(1031,626);
    ui->date->setText(QString("%1.%2.%3").arg(QString::number(date->year,10)).arg(QString::number(date->month,10)).arg(QString::number(date->day,10)));
    ui->bookOperation->setVisible(false);   //����Ա��ʼ���ܶ��ߣ����߳�ʼ�����Լ�
    if(reader==theUser)
    {
        ui->model->setText(QString::fromLocal8Bit("����ģʽ"));
        ui->welcome->setText(QString::fromLocal8Bit(attentionP->name));
        ui->addBook->setVisible(false);
        ui->addBook_bg->setVisible(false);
        ui->addPeople->setVisible(false);
        ui->addPeople_bg->setVisible(false);
        ui->allBook->setVisible(false);
        ui->allBook_bg->setVisible(false);
        ui->allPeople->setVisible(false);
        ui->allPeople_bg->setVisible(false);
        ui->peopelScope->setVisible(false);
        initMyInformation();
    }
    else
    {
        ui->model->setText(QString::fromLocal8Bit("����Աģʽ"));
        ui->welcome->setText(QString::fromLocal8Bit("����Ա"));
        ui->bookScope->setVisible(false);
        ui->myInformation->setVisible(false);
        ui->myInformation_bg->setVisible(false);
    }
    ui->editPassword->setEnabled(false);
}

void MainWindow::initMyInformation()
{
    ui->personName->setText(QString::fromLocal8Bit(attentionP->name));
    ui->personID->setText(QString::number(attentionP->id,10));
    if(teacher==attentionP->job)
    {
        ui->job->setText(QString::fromLocal8Bit("��ʦ"));
        ui->academy->setText(QString::fromLocal8Bit("��"));
    }
    else
    {
        ui->job->setText(QString::fromLocal8Bit("ѧ��"));
        ui->academy->setText(QString::fromLocal8Bit(attentionP->academy));
    }
    ui->password->setText(QString::fromLocal8Bit(attentionP->password));
    ui->credit->setText(QString::number(attentionP->credit,10));
    ui->borrowNumber->setText(QString::number(attentionP->borrowNumber,10));
    ui->reserveNumber->setText(QString::number(attentionP->reserveNumber,10));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logout_clicked()
{
    int r=QMessageBox::question(this,tr("Warning"),QString::fromLocal8Bit("ȷ��Ҫ�˳���"),QMessageBox::Yes|QMessageBox::Default,QMessageBox::No|QMessageBox::Escape);
    if (r==QMessageBox::Yes)
    {
        stopTimer=0;
        savePeople(0);
        saveBook(0);
        close();
    }
}

void MainWindow::on_editPassword_clicked()
{
    bool ok=false;
    QString rePassword=QInputDialog::getText(this,tr("Warning"),QString::fromLocal8Bit("���ظ����룺"),QLineEdit::Password,QString::null,&ok);
    if(ok&&!rePassword.isEmpty())
    {
        QByteArray T1=ui->password->text().toLocal8Bit(),T2;
        char * C1=T1.data(),* C2;
        T2=rePassword.toLocal8Bit();
        C2=T2.data();
        if(0==strcmp(C1,C2))
        {
            strcpy(attentionP->password,C1);
            savePeople(0);
            QMessageBox::information(this,tr("OK"),QString::fromLocal8Bit("�޸�����ɹ���"),QMessageBox::Yes);
        }
        else
        {
            initMyInformation();
            QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("�ظ��������"),QMessageBox::Yes);
        }
    }
    else
        initMyInformation();
    ui->editPassword->setEnabled(false);
}

void MainWindow::on_password_textChanged(const QString &arg1)
{
    ui->editPassword->setEnabled(true);
}
