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
    //��ʼ�����
    ui->peopleList->setWindowTitle(QString::fromLocal8Bit("������Ϣ"));  //����
    ui->peopleList->setEditTriggers(QAbstractItemView::NoEditTriggers);   //����ֹ�༭
    ui->peopleList->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ�еķ�ʽ
   //����������
    ui->peopleList->setColumnCount(8);
    ui->peopleList->setRowCount(0);
   //����ÿ�п�
    ui->peopleList->setColumnWidth(0,120);
    ui->peopleList->setColumnWidth(1,160);
    ui->peopleList->setColumnWidth(2,100);
    ui->peopleList->setColumnWidth(3,170);
    ui->peopleList->setColumnWidth(4,70);
    ui->peopleList->setColumnWidth(5,70);
    ui->peopleList->setColumnWidth(6,70);
    ui->peopleList->setColumnWidth(7,120);
    //���ñ�ͷ
    QStringList header;
    header.append(QString::fromLocal8Bit("��������"));
    header.append(QString::fromLocal8Bit("ID"));
    header.append(QString::fromLocal8Bit("ְҵ"));
    header.append(QString::fromLocal8Bit("ѧԺ"));
    header.append(QString::fromLocal8Bit("����"));
    header.append(QString::fromLocal8Bit("������"));
    header.append(QString::fromLocal8Bit("ԤԼ��"));
    header.append(QString::fromLocal8Bit("����"));
    ui->peopleList->setHorizontalHeaderLabels(header);
    int row = ui->peopleList->rowCount(); //��ȡ�������
    personNode ppointer=peopleHead->nextPerson;
    QPushButton * detail[peopleNUM];
    for(int i=0;ppointer;i++,ppointer=ppointer->nextPerson)
    {
        ui->peopleList->setRowCount(row+1+i);  //����һ��
        ui->peopleList->setItem(row+i,0,new QTableWidgetItem(QString::fromLocal8Bit(ppointer->name)));
        ui->peopleList->setItem(row+i,1,new QTableWidgetItem(QString::number(ppointer->id,10)));
        if(teacher==ppointer->job)
            ui->peopleList->setItem(row+i,2,new QTableWidgetItem(QString::fromLocal8Bit("��ʦ")));
        else
        {
            ui->peopleList->setItem(row+i,2,new QTableWidgetItem(QString::fromLocal8Bit("ѧ��")));
            ui->peopleList->setItem(row+i,3,new QTableWidgetItem(QString::fromLocal8Bit(ppointer->academy)));
        }
        ui->peopleList->setItem(row+i,4,new QTableWidgetItem(QString::number(ppointer->credit,10)));
        ui->peopleList->setItem(row+i,5,new QTableWidgetItem(QString::number(ppointer->borrowNumber,10)));
        ui->peopleList->setItem(row+i,6,new QTableWidgetItem(QString::number(ppointer->reserveNumber,10)));
        detail[i]=new QPushButton(QString::fromLocal8Bit("�鿴��Ϣ"));
        detail[i]->setEnabled(true);
        ui->peopleList->setCellWidget(row+i,7,detail[i]);
    }
}

PeopleInformation::~PeopleInformation()
{
    delete ui;
}
