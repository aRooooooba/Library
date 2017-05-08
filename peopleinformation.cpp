#include "peopleinformation.h"
#include "ui_peopleinformation.h"
#include "dataStruct.h"
#include <QTableWidgetItem>
#include <QPushButton>

extern personNode peopleHead,peopleTail,attentionP;
extern int teacher,student,peopleNUM;

PeopleInformation::PeopleInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PeopleInformation)
{
    ui->setupUi(this);
    ui->setupUi(this);
    //初始化表格
    ui->peopleList->setWindowTitle(QString::fromLocal8Bit("人物信息"));  //表名
    ui->peopleList->setEditTriggers(QAbstractItemView::NoEditTriggers);   //表格禁止编辑
    ui->peopleList->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
   //设置行列数
    ui->peopleList->setColumnCount(8);
    ui->peopleList->setRowCount(0);
   //设置每列宽
    ui->peopleList->setColumnWidth(0,120);
    ui->peopleList->setColumnWidth(1,160);
    ui->peopleList->setColumnWidth(2,100);
    ui->peopleList->setColumnWidth(3,170);
    ui->peopleList->setColumnWidth(4,70);
    ui->peopleList->setColumnWidth(5,70);
    ui->peopleList->setColumnWidth(6,70);
    ui->peopleList->setColumnWidth(7,120);
    //设置表头
    QStringList header;
    header.append(QString::fromLocal8Bit("姓名书名"));
    header.append(QString::fromLocal8Bit("ID"));
    header.append(QString::fromLocal8Bit("职业"));
    header.append(QString::fromLocal8Bit("学院"));
    header.append(QString::fromLocal8Bit("信誉"));
    header.append(QString::fromLocal8Bit("借阅数"));
    header.append(QString::fromLocal8Bit("预约数"));
    header.append(QString::fromLocal8Bit("操作"));
    ui->peopleList->setHorizontalHeaderLabels(header);
    int row = ui->peopleList->rowCount(); //获取表格行数
    personNode ppointer=peopleHead->nextPerson;
    QPushButton * detail[peopleNUM];
    for(int i=0;ppointer;i++,ppointer=ppointer->nextPerson)
    {
        ui->peopleList->setRowCount(row+1+i);  //表格加一行
        ui->peopleList->setItem(row+i,0,new QTableWidgetItem(QString::fromLocal8Bit(ppointer->name)));
        ui->peopleList->setItem(row+i,1,new QTableWidgetItem(QString::number(ppointer->id,10)));
        if(teacher==ppointer->job)
            ui->peopleList->setItem(row+i,2,new QTableWidgetItem(QString::fromLocal8Bit("教师")));
        else
        {
            ui->peopleList->setItem(row+i,2,new QTableWidgetItem(QString::fromLocal8Bit("学生")));
            ui->peopleList->setItem(row+i,3,new QTableWidgetItem(QString::fromLocal8Bit(ppointer->academy)));
        }
        ui->peopleList->setItem(row+i,4,new QTableWidgetItem(QString::number(ppointer->credit,10)));
        ui->peopleList->setItem(row+i,5,new QTableWidgetItem(QString::number(ppointer->borrowNumber,10)));
        ui->peopleList->setItem(row+i,6,new QTableWidgetItem(QString::number(ppointer->reserveNumber,10)));
        detail[i]=new QPushButton(QString::fromLocal8Bit("查看信息"));
        detail[i]->setEnabled(true);
        ui->peopleList->setCellWidget(row+i,7,detail[i]);
    }
}

PeopleInformation::~PeopleInformation()
{
    delete ui;
}
