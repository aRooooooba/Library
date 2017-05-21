#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataStruct.h"
#include "functions.h"
#include "addpeople.h"
#include "addbook.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDialog>

bookNode BHead;
personNode PHead;
int limit,BNUM,PNUM,needToCopy,SBook;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initializeUI();
    needToCopy=0;
}

void MainWindow::initializeUI()
{
    this->setFixedSize(1031,626);
    ui->date->setText(QString("%1.%2.%3").arg(QString::number(date->year,10)).arg(QString::number(date->month,10)).arg(QString::number(date->day,10)));
    if(reader==theUser)
    {
        BHead=bookHead;
        BNUM=bookNUM;
        ui->model->setText(QString::fromLocal8Bit("读者模式"));
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
        SBook=1;
        ui->bookName->setEnabled(false);
        ui->author->setEnabled(false);
        ui->publisher->setEnabled(false);
        ui->description->setEnabled(false);
        ui->editLimit->setVisible(false);
        ui->editLimit_bg->setVisible(false);
        ui->borrowerInformation->setVisible(false);
        ui->borrowerInformation_bg->setVisible(false);
        ui->reserverInformation->setVisible(false);
        ui->reserverInformation_bg->setVisible(false);
        ui->ensured->setVisible(false);
        ui->cancel->setVisible(false);
        initPersonInformation();
        initBookList();
    }
    else
    {
        PHead=peopleHead;
        PNUM=peopleNUM;
        BHead=bookHead;
        BNUM=bookNUM;
        ui->bookOperation->setVisible(false);   //管理员初始化管读者，读者初始化管自己
        ui->bookScope->setVisible(false);
        SBook=0;
        ui->model->setText(QString::fromLocal8Bit("管理员模式"));
        ui->welcome->setText(QString::fromLocal8Bit("管理员"));
        ui->bookScope->setVisible(false);
        ui->myInformation->setVisible(false);
        ui->myInformation_bg->setVisible(false);
        ui->password->setEnabled(false);
        ui->borrow->setVisible(false);
        ui->return_2->setVisible(false);
        ui->noReserve->setVisible(false);
        ui->editPassword->setVisible(false);
        ui->editPassword_bg->setVisible(false);
        ui->ensured->setVisible(false);
        ui->cancel->setVisible(false);
        initPeopleList();
    }
    ui->editPassword->setEnabled(false);
}

void MainWindow::initPersonInformation()
{
    ui->bookOperation->setVisible(false);
    ui->personOperation->setVisible(true);
    ui->personName->setText(QString::fromLocal8Bit(removeEnter(attentionP->name)));
    ui->personID->setText(QString::number(attentionP->id,10));
    if(teacher==attentionP->job)
    {
        ui->job->setText(QString::fromLocal8Bit("教师"));
        ui->academy->setText(QString::fromLocal8Bit("无"));
    }
    else
    {
        ui->job->setText(QString::fromLocal8Bit("学生"));
        ui->academy->setText(QString::fromLocal8Bit(removeEnter(attentionP->academy)));
    }
    if(reader==theUser)
        ui->password->setText(QString::fromLocal8Bit(attentionP->password));
    else
        ui->password->setText(tr("******"));
    ui->credit->setText(QString::number(attentionP->credit,10));
    ui->borrowNumber->setText(QString::number(attentionP->borrowNumber,10));
    if(0<attentionP->borrowNumber)
        ui->borrowedInformation->setEnabled(true);
    else
        ui->borrowedInformation->setEnabled(false);
    ui->reserveNumber->setText(QString::number(attentionP->reserveNumber,10));
    if(0<attentionP->reserveNumber)
        ui->reservedInformation->setEnabled(true);
    else
        ui->reservedInformation->setEnabled(false);
}

void MainWindow::initBookInformation()
{
    ui->personOperation->setVisible(false);
    ui->bookOperation->setVisible(true);
    ui->ensured->setVisible(false);
    ui->cancel->setVisible(false);
    ui->bookName->setText(QString::fromLocal8Bit(removeEnter(attentionB->name)));
    ui->author->setText(QString::fromLocal8Bit(removeEnter(attentionB->author)));
    ui->publisher->setText(QString::fromLocal8Bit(removeEnter(attentionB->publisher)));
    ui->bookID->setText(QString::fromLocal8Bit(attentionB->id));
    ui->boughtTime->setText(QString("%1.%2.%3").arg(QString::number(attentionB->boughtTime[0],10)).arg(QString::number(attentionB->boughtTime[1],10)).arg(QString::number(attentionB->boughtTime[2],10)));
    ui->number->setText(QString::number(attentionB->number,10));
    if(teacher==attentionB->limit)
        ui->limit->setText(QString::fromLocal8Bit("仅教师可借阅"));
    else
        ui->limit->setText(QString::fromLocal8Bit("任何人均可借阅"));
    limit=attentionB->limit;
    ui->description->setPlainText(QString::fromLocal8Bit(removeEnter(attentionB->description)));
    if(!attentionB->isBorrowed)
    {
        ui->borrower->setText(QString::fromLocal8Bit("无"));
        ui->returnTime->setText(QString::fromLocal8Bit("无"));
        ui->borrowerInformation->setEnabled(false);
    }
    else
    {
        ui->borrower->setText(QString::number(attentionB->borrower,10));
        ui->returnTime->setText(QString("%1.%2.%3").arg(QString::number(attentionB->returnTime[0],10)).arg(QString::number(attentionB->returnTime[1],10)).arg(QString::number(attentionB->returnTime[2],10)));
        ui->borrowerInformation->setEnabled(true);
    }
    ui->reserverNumber->setText(QString::number(attentionB->reserveNumber,10));
    if(!attentionB->reserveNumber)
        ui->reserverInformation->setEnabled(false);
    else
        ui->reserverInformation->setEnabled(true);
    if(reader==theUser)
    {
        if(attentionB->borrower==attentionP->id)
        {
            ui->borrower->setText(QString::fromLocal8Bit("我"));
            ui->borrow->setVisible(false);
            ui->return_2->setVisible(true);
            ui->noReserve->setVisible(false);
        }
        else
        {
            if(attentionB->isBorrowed)
                ui->borrower->setText(tr("******"));
            int i=attentionB->reserveQueue.front;
            for(;i!=attentionB->reserveQueue.rear&&attentionB->reserveQueue.base[i]!=attentionP->id;i=(i+1)%MAXRNUM);
            if(attentionB->reserveQueue.rear==i)    //该用户还没有预约该书
            {
                ui->borrow->setVisible(true);
                ui->return_2->setVisible(false);
                ui->noReserve->setVisible(false);
            }
            else
            {
                ui->borrow->setVisible(false);
                ui->return_2->setVisible(false);
                ui->noReserve->setVisible(true);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logout_clicked()
{
    int r=QMessageBox::warning(this,tr("Warning"),QString::fromLocal8Bit("确定要退出吗？"),QMessageBox::Yes|QMessageBox::Default,QMessageBox::No|QMessageBox::Escape);
    if (r==QMessageBox::Yes)
    {
        stopTimer=0;
        attentionB=NULL;
        attentionP=NULL;
        savePeople(0);
        saveBook(0);
        close();
    }
}

void MainWindow::on_editPassword_clicked()
{
    bool ok=false;
    QString rePassword=QInputDialog::getText(this,tr("Warning"),QString::fromLocal8Bit("请重复密码："),QLineEdit::Password,QString::null,&ok);
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
            QMessageBox::information(this,tr("OK"),QString::fromLocal8Bit("修改密码成功！"),QMessageBox::Yes);
        }
        else
        {
            initPersonInformation();
            QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("重复密码错误！"),QMessageBox::Yes);
        }
    }
    else
        initPersonInformation();
    ui->editPassword->setEnabled(false);
}

void MainWindow::on_password_textChanged()
{
    ui->editPassword->setEnabled(true);
}

void MainWindow::on_addPeople_clicked()
{
    addPeople a;
    if(QDialog::Accepted==a.exec())
        savePeople(0);
}

void MainWindow::on_addBook_clicked()
{
    addBook a;
    if(QDialog::Accepted==a.exec())
        saveBook(0);
}

void MainWindow::on_myInformation_clicked()
{
    needToCopy=0;
    initPersonInformation();
}

void MainWindow::initPeopleList()
{
    //初始化表格
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //表格禁止编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
   //设置行列数
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(PNUM);
   //设置每列宽
    ui->tableWidget->setColumnWidth(0,80);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,60);
    ui->tableWidget->setColumnWidth(3,160);
    ui->tableWidget->setColumnWidth(4,70);
    ui->tableWidget->setColumnWidth(5,70);
    ui->tableWidget->setColumnWidth(6,70);
    //设置表头
    QStringList header;
    header.append(QString::fromLocal8Bit("姓名"));
    header.append(QString::fromLocal8Bit("ID"));
    header.append(QString::fromLocal8Bit("职业"));
    header.append(QString::fromLocal8Bit("学院"));
    header.append(QString::fromLocal8Bit("信誉"));
    header.append(QString::fromLocal8Bit("借阅数"));
    header.append(QString::fromLocal8Bit("预约数"));
    ui->tableWidget->setHorizontalHeaderLabels(header);
    personNode ppointer=PHead->nextPerson;
    for(int i=0;ppointer;i++,ppointer=ppointer->nextPerson)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromLocal8Bit(ppointer->name)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(ppointer->id,10)));
        if(teacher==ppointer->job)
        {
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromLocal8Bit("教师")));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromLocal8Bit("无")));
        }
        else
        {
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromLocal8Bit("学生")));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromLocal8Bit(ppointer->academy)));
        }
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(ppointer->credit,10)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(ppointer->borrowNumber,10)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(ppointer->reserveNumber,10)));
    }
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(locateP(int)));
}

void MainWindow::locateP(int i)
{
    if(i<PNUM)
    {
        personNode ppointer=PHead->nextPerson;
        for(int j=0;j<i;j++)
            ppointer=ppointer->nextPerson;
        attentionP=ppointer;
        initPersonInformation();
    }
}

void MainWindow::initBookList()
{
    //初始化表格
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //表格禁止编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
   //设置行列数
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(BNUM);
   //设置每列宽
    ui->tableWidget->setColumnWidth(0,160);
    ui->tableWidget->setColumnWidth(1,160);
    ui->tableWidget->setColumnWidth(2,70);
    ui->tableWidget->setColumnWidth(3,70);
    //设置表头
    QStringList header;
    header.append(QString::fromLocal8Bit("书名"));
    header.append(QString::fromLocal8Bit("ID"));
    header.append(QString::fromLocal8Bit("数量"));
    header.append(QString::fromLocal8Bit("在借"));
    ui->tableWidget->setHorizontalHeaderLabels(header);
    bookNode bpointer=BHead->nextBook;
    for(int i=0;bpointer;i++,bpointer=bpointer->nextBook)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromLocal8Bit(bpointer->name)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromLocal8Bit(bpointer->id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(bpointer->number,10)));
        if(1==bpointer->isBorrowed)
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromLocal8Bit("是")));
        else
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromLocal8Bit("否")));
    }
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(locateB(int)));
}

void MainWindow::locateB(int i)
{
    if(i<BNUM)
    {
        bookNode bpointer=BHead->nextBook;
        for(int j=0;j<i;j++)
            bpointer=bpointer->nextBook;
        attentionB=bpointer;
        initBookInformation();
    }
}

void MainWindow::on_editLimit_clicked()
{
    limit=1-limit;
    if(teacher==limit)
        ui->limit->setText(QString::fromLocal8Bit("仅教师可借阅"));
    else
        ui->limit->setText(QString::fromLocal8Bit("任何人均可借阅"));
    ui->ensured->setVisible(true);
    ui->cancel->setVisible(true);
}

void MainWindow::on_ensured_clicked()
{
    QByteArray T;
    char * C;
    T=ui->bookName->text().toLocal8Bit();
    C=T.data();
    strcpy(attentionB->name,appendEnter(C));
    T=ui->author->text().toLocal8Bit();
    C=T.data();
    strcpy(attentionB->author,appendEnter(C));
    T=ui->publisher->text().toLocal8Bit();
    C=T.data();
    strcpy(attentionB->publisher,appendEnter(C));
    attentionB->limit=limit;
    T=ui->description->toPlainText().toLocal8Bit();
    C=T.data();
    strcpy(attentionB->description,appendEnter(C));
    if(needToCopy)
    {
        bookNode bpointer=bookHead->nextBook;
        for(;0!=strcmp(attentionB->id,bpointer->id);bpointer=bpointer->nextBook);
        copyInfoB(bpointer,attentionB);
    }
    ui->ensured->setVisible(false);
    ui->cancel->setVisible(false);
    saveBook(0);
}

void MainWindow::on_cancel_clicked()
{
    initBookInformation();
    ui->ensured->setVisible(false);
    ui->cancel->setVisible(false);
}

void MainWindow::on_allPeople_clicked()
{
    SBook=0;
    ui->peopelScope->setVisible(true);
    ui->bookScope->setVisible(false);
    needToCopy=0;
    PHead=peopleHead;
    PNUM=peopleNUM;
    initPeopleList();
}

void MainWindow::on_allBook_clicked()
{
    SBook=1;
    ui->peopelScope->setVisible(false);
    ui->bookScope->setVisible(true);
    needToCopy=0;
    BHead=bookHead;
    BNUM=bookNUM;
    initBookList();
}

void MainWindow::on_bookName_textEdited()
{
    ui->ensured->setVisible(true);
    ui->cancel->setVisible(true);
}

void MainWindow::on_author_textEdited()
{
    ui->ensured->setVisible(true);
    ui->cancel->setVisible(true);
}

void MainWindow::on_publisher_textEdited()
{
    ui->ensured->setVisible(true);
    ui->cancel->setVisible(true);
}

void MainWindow::on_description_textChanged()
{
    QByteArray T;
    char * C;
    T=ui->description->toPlainText().toLocal8Bit();
    C=T.data();
    if(0!=strcmp(attentionB->description,appendEnter(C)))
    {
        ui->ensured->setVisible(true);
        ui->cancel->setVisible(true);
    }
}

void MainWindow::on_borrow_clicked()
{
    if(1==attentionB->isBorrowed)
    {
        if(QMessageBox::Yes==QMessageBox::question(this,tr("Question"),QString::fromLocal8Bit("该书已被借出，是否预约？"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
        {
            borrowedBookNode bpointer=(borrowedBookNode)malloc(sizeof(borrowedBook));
            bpointer->nextBB=NULL;
            strcpy(bpointer->id,attentionB->id);
            attentionP->reserveNumber++;
            attentionP->reservedBTail->nextBB=bpointer;
            attentionP->reservedBTail=bpointer;
            attentionB->reserveNumber++;
            enQueue(&attentionB->reserveQueue,attentionP->id);
            QMessageBox::information(this,tr("OK"),QString::fromLocal8Bit("预约成功！"),QMessageBox::Yes);
            saveBook(0);
            savePeople(0);
            initBookInformation();
            initBookList();
        }
    }
    else if(attentionB->limit>attentionP->job)
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("权限不足！"),QMessageBox::Yes);
    else if(attentionP->borrowNumber>attentionP->credit/25)
        QMessageBox::critical(this,tr("Error"),QString::fromLocal8Bit("信用不足！"),QMessageBox::Yes);
    else
    {
        borrowedBookNode bpointer=(borrowedBookNode)malloc(sizeof(borrowedBook));
        bpointer->nextBB=NULL;
        strcpy(bpointer->id,attentionB->id);
        bpointer->returnTime[0]=date->year;
        bpointer->returnTime[1]=date->month+2;
        if(12<bpointer->returnTime[1])
        {
            bpointer->returnTime[1]-=12;
            bpointer->returnTime[0]++;
        }
        bpointer->returnTime[2]=date->day;
        attentionB->returnTime[0]=bpointer->returnTime[0];
        attentionB->returnTime[1]=bpointer->returnTime[1];
        attentionB->returnTime[2]=bpointer->returnTime[2];
        attentionP->borrowNumber++;
        attentionP->borrowedBTail->nextBB=bpointer;
        attentionP->borrowedBTail=bpointer;
        attentionB->isBorrowed=1;
        attentionB->borrower=attentionP->id;
        QMessageBox::information(this,tr("OK"),QString::fromLocal8Bit("借书成功！"),QMessageBox::Yes);
        savePeople(0);
        saveBook(0);
        initBookInformation();
        initBookList();
    }
}

void MainWindow::on_return_2_clicked()
{
    attentionP->borrowNumber--;
    borrowedBookNode bpointer1=attentionP->bookBorrowed,bpointer2=NULL;
    for(bpointer2=attentionP->bookBorrowed->nextBB;0!=strcmp(attentionB->id,bpointer2->id);bpointer2=bpointer2->nextBB)
        bpointer1=bpointer2;
    bpointer1->nextBB=bpointer2->nextBB;
    if(!bpointer1->nextBB)
        attentionP->borrowedBTail=bpointer1;
    free(bpointer2);
    attentionB->isBorrowed=0;
    attentionB->borrower=0;
    attentionB->returnTime[0]=date->year;
    attentionB->returnTime[1]=date->month;
    attentionB->returnTime[2]=date->day;
    QMessageBox::information(this,tr("OK"),QString::fromLocal8Bit("还书成功！"),QMessageBox::Yes);
    savePeople(0);
    saveBook(0);
    initBookInformation();
    initBookList();
}

void MainWindow::on_noReserve_clicked()
{
    attentionP->reserveNumber--;
    borrowedBookNode bpointer1=attentionP->bookReserved,bpointer2=NULL;
    for(bpointer2=attentionP->bookReserved->nextBB;0!=strcmp(attentionB->id,bpointer2->id);bpointer2=bpointer2->nextBB)
        bpointer1=bpointer2;
    bpointer1->nextBB=bpointer2->nextBB;
    if(!bpointer1->nextBB)
        attentionP->reservedBTail=bpointer1;
    free(bpointer2);
    attentionB->reserveNumber--;
    int i;
    for(i=attentionB->reserveQueue.front;attentionB->reserveQueue.base[i]!=attentionP->id;i=(i+1)%MAXRNUM);
    for(;i!=attentionB->reserveQueue.rear;i=(i+1)%MAXRNUM)
        attentionB->reserveQueue.base[i]=attentionB->reserveQueue.base[(i+1)%MAXRNUM];
    attentionB->reserveQueue.rear--;
    if(-1==attentionB->reserveQueue.rear)
        attentionB->reserveQueue.rear=MAXRNUM;
    QMessageBox::information(this,tr("OK"),QString::fromLocal8Bit("取消预约成功！"),QMessageBox::Yes);
    savePeople(0);
    saveBook(0);
    initBookInformation();
    initBookList();
}

void MainWindow::on_borrowerInformation_clicked()
{
    personNode ppointer1=peopleHead,ppointer2=NULL;
    for(ppointer2=peopleHead->nextPerson;attentionB->borrower!=ppointer2->id;ppointer2=ppointer2->nextPerson)
        ppointer1=ppointer2;
    PHead=ppointer1;
    PNUM=1;
    initPeopleList();
}

void MainWindow::on_reserverInformation_clicked()
{
    needToCopy=1;
    PHead=(personNode)malloc(sizeof(person));
    PHead->nextPerson=NULL;
    personNode ppointer1=PHead,ppointer2=NULL,ppointer3=NULL;
    for(int i=attentionB->reserveQueue.front;i<attentionB->reserveNumber;i=(i+1)%MAXRNUM)
    {
        ppointer2=(personNode)malloc(sizeof(person));
        ppointer2->nextPerson=NULL;
        for(ppointer3=peopleHead->nextPerson;attentionB->reserveQueue.base[i]!=ppointer3->id;ppointer3=ppointer3->nextPerson);
        copyInfoP(ppointer2,ppointer3);
        ppointer1->nextPerson=ppointer2;
        ppointer1=ppointer2;
    }
    PNUM=attentionB->reserveNumber;
    initPeopleList();
}

void MainWindow::on_borrowedInformation_clicked()
{
    needToCopy=1;
    BHead=(bookNode)malloc(sizeof(book));
    BHead->nextBook=NULL;
    bookNode bpointer1=BHead,bpointer2=NULL,bpointer3=NULL;
    borrowedBookNode BBpointer=attentionP->bookBorrowed->nextBB;
    for(int i=0;i<attentionP->borrowNumber;i++)
    {
        bpointer2=(bookNode)malloc(sizeof(book));
        bpointer2->nextBook=NULL;
        for(bpointer3=bookHead->nextBook;0!=strcmp(bpointer3->id,BBpointer->id);bpointer3=bpointer3->nextBook);
        copyInfoB(bpointer2,bpointer3);
        bpointer1->nextBook=bpointer2;
        bpointer1=bpointer2;
        BBpointer=BBpointer->nextBB;
    }
    BNUM=attentionP->borrowNumber;
    initBookList();
}

void MainWindow::on_reservedInformation_clicked()
{
    needToCopy=1;
    BHead=(bookNode)malloc(sizeof(book));
    BHead->nextBook=NULL;
    bookNode bpointer1=BHead,bpointer2=NULL,bpointer3=NULL;
    borrowedBookNode RBpointer=attentionP->bookReserved->nextBB;
    for(int i=0;i<attentionP->reserveNumber;i++)
    {
        bpointer2=(bookNode)malloc(sizeof(book));
        bpointer2->nextBook=NULL;
        for(bpointer3=bookHead->nextBook;0!=strcmp(bpointer3->id,RBpointer->id);bpointer3=bpointer3->nextBook);
        copyInfoB(bpointer2,bpointer3);
        bpointer1->nextBook=bpointer2;
        bpointer1=bpointer2;
        RBpointer=RBpointer->nextBB;
    }
    BNUM=attentionP->reserveNumber;
    initBookList();
}

void MainWindow::on_search_clicked()
{
    if(ui->keyWords->text().isEmpty())
    {
        if(0==SBook)
        {
            PHead=peopleHead;
            PNUM=peopleNUM;
            initPeopleList();
        }
        else
        {
            BHead=bookHead;
            BNUM=bookNUM;
            initBookList();
        }
    }
    else
    {
        int i;
        QByteArray T=ui->keyWords->text().toLocal8Bit();
        char * C=T.data();
        if(0==SBook)
        {
            i=ui->peopelScope->currentIndex();
            PNUM=searchPeople(PHead,i,C);
            initPeopleList();
        }
        else
        {
            i=ui->bookScope->currentIndex();
            BNUM=searchBook(BHead,i,C);
            initBookList();
        }
    }
}
