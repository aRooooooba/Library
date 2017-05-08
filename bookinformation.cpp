#include "bookinformation.h"
#include "ui_bookinformation.h"
#include "dataStruct.h"
#include "copyinfob.h"
#include "bookdetail.h"
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
#include <QSignalMapper>

extern bookNode bookHead,bookTail,attentionB;
extern int teacher,student,bookNUM;

void locateB();

BookInformation::BookInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookInformation)
{
    ui->setupUi(this);
    //初始化表格
    ui->bookList->setWindowTitle(QString::fromLocal8Bit("书籍信息"));  //表名
    ui->bookList->setEditTriggers(QAbstractItemView::NoEditTriggers);   //表格禁止编辑
    ui->bookList->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
   //设置行列数
    ui->bookList->setColumnCount(6);
    ui->bookList->setRowCount(0);
   //设置每列宽
    ui->bookList->setColumnWidth(0,170);
    ui->bookList->setColumnWidth(1,160);
    ui->bookList->setColumnWidth(2,120);
    ui->bookList->setColumnWidth(3,70);
    ui->bookList->setColumnWidth(4,70);
    ui->bookList->setColumnWidth(5,120);
    //设置表头
    QStringList header;
    header.append(QString::fromLocal8Bit("书名"));
    header.append(QString::fromLocal8Bit("ID"));
    header.append(QString::fromLocal8Bit("购入日期"));
    header.append(QString::fromLocal8Bit("数量"));
    header.append(QString::fromLocal8Bit("在借"));
    header.append(QString::fromLocal8Bit("操作"));
    ui->bookList->setHorizontalHeaderLabels(header);
    int row = ui->bookList->rowCount(); //获取表格行数
    bookNode bpointer=bookHead->nextBook;
    QPushButton * detail[bookNUM];
    signalMapper =new QSignalMapper(this);
    for(int i=0;bpointer;i++,bpointer=bpointer->nextBook)
    {
        ui->bookList->setRowCount(row+1+i);  //表格加一行
        ui->bookList->setItem(row+i,0,new QTableWidgetItem(QString::fromLocal8Bit(bpointer->name)));
        ui->bookList->setItem(row+i,1,new QTableWidgetItem(QString::fromLocal8Bit(bpointer->id)));
        ui->bookList->setItem(row+i,2,new QTableWidgetItem(QString("%1.%2.%3").arg(QString::number(bpointer->boughtTime[0],10)).arg(QString::number(bpointer->boughtTime[1],10)).arg(QString::number(bpointer->boughtTime[2],10))));
        ui->bookList->setItem(row+i,3,new QTableWidgetItem(QString::number(bpointer->number,10)));
        if(1==bpointer->isBorrowed)
            ui->bookList->setItem(row+i,4,new QTableWidgetItem(QString::fromLocal8Bit("是")));
        else
            ui->bookList->setItem(row+i,4,new QTableWidgetItem(QString::fromLocal8Bit("否")));
        detail[i]=new QPushButton(QString::fromLocal8Bit("查看信息"));
        detail[i]->setEnabled(true);
        ui->bookList->setCellWidget(row+i,5,detail[i]);
        connect(detail[i],SIGNAL(clicked()),signalMapper,SLOT(map()));
        signalMapper->setMapping(detail[i],i);
    }
    connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(locateB(int)));
}

BookInformation::~BookInformation()
{
    delete ui;
}

void BookInformation::locateB(int i)
{
    bookNode bpointer=bookHead->nextBook;
    for(int j=0;j<i;j++)
        bpointer=bpointer->nextBook;
    copyInfoB(bpointer,attentionB);
    BookDetail b;
    b.exec();
}
