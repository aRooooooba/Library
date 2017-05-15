#include "mainwindow.h"
#include "login.h"
#include "dataStruct.h"
#include <QApplication>

personNode peopleHead,peopleTail,attentionP;
bookNode bookHead,bookTail,attentionB;
int teacher,student,theUser,reader,administrator,bookNUM,peopleNUM,MAXRNUM;
time date;

void initialize();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initialize();
    login L;
    MainWindow w;
    while(QDialog::Accepted==L.exec())
    {
        w.show();
        a.exec();
    }
    return 0;
}

void initialize()
{
    teacher=1;
    student=0;
    reader=0;
    administrator=1;
    date.day=0;
    date.month=0;
    date.year=0;
    bookNUM=0;
    peopleNUM=0;
    MAXRNUM=100;
    peopleHead=(personNode)malloc(sizeof(person));
    peopleHead->nextPerson=NULL;
    peopleTail=NULL;
    attentionP=(personNode)malloc(sizeof(person));
    attentionP->nextPerson=NULL;
    attentionB=(bookNode)malloc(sizeof(book));
    attentionB->nextBook=NULL;
    bookHead=(bookNode)malloc(sizeof(book));
    bookHead->nextBook=NULL;
    bookTail=NULL;
}
