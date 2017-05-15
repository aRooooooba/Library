#include "login.h"
#include "ui_login.h"
#include "addpeople.h"
#include <QToolTip>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint |Qt::WindowSystemMenuHint|Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint);

}

login::~login()
{
    delete ui;
}

void login::on_exit_clicked()
{
    reject();
}

void login::on_register_2_clicked()
{
    addPeople a;
    a.exec();
}
