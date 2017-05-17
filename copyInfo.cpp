#include <cstring>
#include <cstdlib>
#include "dataStruct.h"
#include "functions.h"

void initQueue2(SqQueue * Q);

void copyInfoB(bookNode &Dest,bookNode Source)
{
    strcpy(Dest->name,Source->name);
    strcpy(Dest->id,Source->id);
    strcpy(Dest->author,Source->author);
    strcpy(Dest->publisher,Source->publisher);
	for(int i=0;i<3;i++)
        Dest->boughtTime[i]=Source->boughtTime[i];
    Dest->number=Source->number;
    strcpy(Dest->description,Source->description);
    Dest->limit=Source->limit;
    Dest->isBorrowed=Source->isBorrowed;
    if(Dest->isBorrowed)
        Dest->borrower=Source->borrower;
    else
        Dest->borrower=0;
    Dest->reserveNumber=Source->reserveNumber;
    if(0!=Dest->reserveNumber)
	{
        initQueue2(&Dest->reserveQueue);
        Dest->reserveQueue.front=Source->reserveQueue.front;
        for(int i=0;i<Dest->reserveNumber;i++)
            Dest->reserveQueue.base[(Dest->reserveQueue.front+i)%MAXRNUM]=Source->reserveQueue.base[(Source->reserveQueue.front+i)%MAXRNUM];
    }
}

void copyInfoP(personNode &Dest,personNode Source)
{
    strcpy(Dest->name, Source->name);
    Dest->job=Source->job;
    Dest->id=Source->id;
    strcpy(Dest->password, Source->password);
    strcpy(Dest->academy,Source->academy);
    Dest->credit=Source->credit;
    Dest->borrowNumber=Source->borrowNumber;
    if(0<Source->borrowNumber)
    {
        borrowedBookNode bpointer1=NULL,bpointer2=NULL,bpointer3=Source->bookBorrowed->nextBB;
        Dest->bookBorrowed=(borrowedBookNode)malloc(sizeof(borrowedBook));
        Dest->bookBorrowed->nextBB=NULL;
        bpointer1=Dest->bookBorrowed;
        for(int i=0;i<Source->borrowNumber;i++)
        {
            bpointer2=(borrowedBookNode)malloc(sizeof(borrowedBook));
            strcpy(bpointer2->id,bpointer3->id);
            for(int j=0;j<3;j++)
                bpointer2->returnTime[j]=bpointer3->returnTime[j];
            bpointer2->nextBB=NULL;
            bpointer1->nextBB=bpointer2;
            bpointer1=bpointer2;
            bpointer3=bpointer3->nextBB;
        }
        Dest->borrowedBTail=bpointer1;
    }
    Dest->reserveNumber=Source->reserveNumber;
    if(0<Source->reserveNumber)
    {
        borrowedBookNode bpointer1=NULL,bpointer2=NULL,bpointer3=Source->bookReserved->nextBB;
        Dest->bookReserved=(borrowedBookNode)malloc(sizeof(borrowedBook));
        Dest->bookReserved->nextBB=NULL;
        bpointer1=Dest->bookReserved;
        for(int i=0;i<Source->reserveNumber;i++)
        {
            bpointer2=(borrowedBookNode)malloc(sizeof(borrowedBook));
            strcpy(bpointer2->id,bpointer3->id);
            bpointer2->nextBB=NULL;
            bpointer1->nextBB=bpointer2;
            bpointer1=bpointer2;
            bpointer3=bpointer3->nextBB;
        }
        Dest->reservedBTail=bpointer1;
    }
}

void initQueue2(SqQueue * Q)
{
	Q->base=(int*)malloc(MAXRNUM*sizeof(int));
	Q->front=Q->rear=0;
}
