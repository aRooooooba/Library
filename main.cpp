#include "mainwindow.h"
#include "loadlogin.h"
#include "saveBook.h"
#include "savePeople.h"
#include "dataStruct.h"
#include <QApplication>
#include <QTextCodec>

personNode peopleHead,peopleTail,attentionP;
bookNode bookHead,bookTail,attentionB;
int teacher,student,theUser,reader,administrator,day,month,year,bookNUM,peopleNUM,MAXRNUM;

void initialize();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::codecForName("GBK");
    initialize();
    Loadlogin load;
    if(load.exec()==QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    return a.exec();
}

void initialize()
{
    teacher=1;
    student=0;
    reader=0;
    administrator=1;
    day=1;
    month=1;
    year=1;
    bookNUM=0;
    peopleNUM=0;
    MAXRNUM=100;
    peopleHead=(personNode)malloc(sizeof(person));
    peopleHead->nextPerson=NULL;
    peopleTail=(personNode)malloc(sizeof(person));
    peopleTail->nextPerson=NULL;
    attentionP=(personNode)malloc(sizeof(person));
    attentionP->nextPerson=NULL;
    attentionB=(bookNode)malloc(sizeof(book));
    attentionB->nextBook=NULL;
    bookHead=(bookNode)malloc(sizeof(book));
    bookHead->nextBook=NULL;
    bookTail=(bookNode)malloc(sizeof(book));
    bookTail->nextBook=NULL;
}
