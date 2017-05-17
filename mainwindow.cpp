#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataStruct.h"
#include "functions.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(reader==theUser)
    {
        ui->model->setText(QString::fromLocal8Bit("管理员模式"));
        ui->welcome->setText(QString::fromLocal8Bit(attentionP->name));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
