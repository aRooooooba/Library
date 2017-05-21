#include "addbook.h"
#include "ui_addbook.h"
#include "dataStruct.h"
#include "functions.h"
#include <cstring>
#include <cstdlib>
#include <QMessageBox>

bookNode bpointer=NULL;
int addedB;

addBook::addBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBook)
{
    ui->setupUi(this);
    this->setFixedSize(435,716);
    bpointer=(bookNode)malloc(sizeof(book));
    bpointer->nextBook=NULL;
    addedB=0;
}

addBook::~addBook()
{
    delete ui;
}

void addBook::on_ensured_clicked()
{
    if(ui->name->text().isEmpty())
    {
        ui->name->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请输入书名！"),QMessageBox::Yes);
    }
    else if(ui->author->text().isEmpty())
    {
        ui->author->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请输入作者！"),QMessageBox::Yes);
    }
    else if(ui->publisher->text().isEmpty())
    {
        ui->publisher->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请输入出版社！"),QMessageBox::Yes);
    }
    else if(ui->number->text().isEmpty()||0==ui->number->text().toInt())
    {
        ui->number->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请输入该书数量！"),QMessageBox::Yes);
    }
    else if(!ui->student->isChecked()&&!ui->teacher->isChecked())
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请选择借阅权限！"),QMessageBox::Yes);
    else if(ui->description->toPlainText().isEmpty())
    {
        ui->description->setFocus();
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("请输入简介！"),QMessageBox::Yes);
    }
    else
    {
        QByteArray T;
        char * C;
        addedB=1;
        T=ui->name->text().toLocal8Bit();
        C=T.data();
        strcpy(bpointer->name,appendEnter(C));
        T=ui->author->text().toLocal8Bit();
        C=T.data();
        strcpy(bpointer->author,appendEnter(C));
        T=ui->publisher->text().toLocal8Bit();
        C=T.data();
        strcpy(bpointer->publisher,appendEnter(C));
        bpointer->boughtTime[0]=date->year;
        bpointer->boughtTime[1]=date->month;
        bpointer->boughtTime[2]=date->day;
        bpointer->returnTime[0]=date->year;
        bpointer->returnTime[1]=date->month;
        bpointer->returnTime[2]=date->day;
        bpointer->number=ui->number->text().toInt();
        bpointer->id[0]=date->year/1000+'0';
        bpointer->id[1]=date->year%1000/100+'0';
        bpointer->id[2]=date->year%100/10+'0';
        bpointer->id[3]=date->year%10+'0';
        bpointer->id[4]=date->month/10+'0';
        bpointer->id[5]=date->month%10+'0';
        bpointer->id[6]=date->day/10+'0';
        bpointer->id[7]=date->day%10+'0';
        int firstLetter;
        firstLetter=getFirstLetter(bpointer->name);
        bpointer->id[8]=firstLetter/10+'0';
        bpointer->id[9]=firstLetter%10+'0';
        firstLetter=getFirstLetter(bpointer->author);
        bpointer->id[10]=firstLetter/10+'0';
        bpointer->id[11]=firstLetter%10+'0';
        firstLetter=getFirstLetter(bpointer->publisher);
        bpointer->id[12]=firstLetter/10+'0';
        bpointer->id[13]=firstLetter%10+'0';
        bpointer->id[14]=oneDayNewBook/10+'0';
        bpointer->id[15]=oneDayNewBook%10+'0';
        bpointer->id[16]='\0';
        T=ui->description->toPlainText().toLocal8Bit();
        C=T.data();
        strcpy(bpointer->description,appendEnter(C));
        if(ui->student->isChecked())
            bpointer->limit=student;
        else if(ui->teacher->isChecked())
            bpointer->limit=teacher;
        bpointer->isBorrowed=0;
        bpointer->borrower=0;
        bpointer->reserveNumber=0;
        bookTail->nextBook=bpointer;
        bookTail=bpointer;
        bookNUM++;
        oneDayNewBook++;
        for(int i=1;i<bpointer->number;i++)
        {
            bpointer=(bookNode)malloc(sizeof(book));
            bpointer->nextBook=NULL;
            copyInfoB(bpointer,bookTail);
            bpointer->id[14]=oneDayNewBook/10+'0';
            bpointer->id[15]=oneDayNewBook%10+'0';
            bookTail->nextBook=bpointer;
            bookTail=bpointer;
            bookNUM++;
            oneDayNewBook++;
        }
        if(QMessageBox::Yes==QMessageBox::question(this,tr("Question"),QString::fromLocal8Bit("是否继续添加？"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
        {
            bpointer=(bookNode)malloc(sizeof(book));
            bpointer->nextBook=NULL;
            ui->name->clear();
            ui->author->clear();
            ui->publisher->clear();
            ui->number->clear();
            ui->description->clear();
            ui->name->setFocus();
        }
        else
            accept();
    }
}

void addBook::on_cancel_clicked()
{
    free(bpointer);
    if(addedB)
        accept();
    else
        reject();
}
