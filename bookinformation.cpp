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
    //��ʼ�����
    ui->bookList->setWindowTitle(QString::fromLocal8Bit("�鼮��Ϣ"));  //����
    ui->bookList->setEditTriggers(QAbstractItemView::NoEditTriggers);   //����ֹ�༭
    ui->bookList->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ�еķ�ʽ
   //����������
    ui->bookList->setColumnCount(6);
    ui->bookList->setRowCount(0);
   //����ÿ�п�
    ui->bookList->setColumnWidth(0,170);
    ui->bookList->setColumnWidth(1,160);
    ui->bookList->setColumnWidth(2,120);
    ui->bookList->setColumnWidth(3,70);
    ui->bookList->setColumnWidth(4,70);
    ui->bookList->setColumnWidth(5,120);
    //���ñ�ͷ
    QStringList header;
    header.append(QString::fromLocal8Bit("����"));
    header.append(QString::fromLocal8Bit("ID"));
    header.append(QString::fromLocal8Bit("��������"));
    header.append(QString::fromLocal8Bit("����"));
    header.append(QString::fromLocal8Bit("�ڽ�"));
    header.append(QString::fromLocal8Bit("����"));
    ui->bookList->setHorizontalHeaderLabels(header);
    int row = ui->bookList->rowCount(); //��ȡ�������
    bookNode bpointer=bookHead->nextBook;
    QPushButton * detail[bookNUM];
    signalMapper =new QSignalMapper(this);
    for(int i=0;bpointer;i++,bpointer=bpointer->nextBook)
    {
        ui->bookList->setRowCount(row+1+i);  //����һ��
        ui->bookList->setItem(row+i,0,new QTableWidgetItem(QString::fromLocal8Bit(bpointer->name)));
        ui->bookList->setItem(row+i,1,new QTableWidgetItem(QString::fromLocal8Bit(bpointer->id)));
        ui->bookList->setItem(row+i,2,new QTableWidgetItem(QString("%1.%2.%3").arg(QString::number(bpointer->boughtTime[0],10)).arg(QString::number(bpointer->boughtTime[1],10)).arg(QString::number(bpointer->boughtTime[2],10))));
        ui->bookList->setItem(row+i,3,new QTableWidgetItem(QString::number(bpointer->number,10)));
        if(1==bpointer->isBorrowed)
            ui->bookList->setItem(row+i,4,new QTableWidgetItem(QString::fromLocal8Bit("��")));
        else
            ui->bookList->setItem(row+i,4,new QTableWidgetItem(QString::fromLocal8Bit("��")));
        detail[i]=new QPushButton(QString::fromLocal8Bit("�鿴��Ϣ"));
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
