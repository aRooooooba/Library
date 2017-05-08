#include <cstring>
#include <cstdlib>
#include <QDebug>
#include "dataStruct.h"

extern int MAXRNUM;

void initQueue2(SqQueue * Q);

void copyInfoB(bookNode bpointer,bookNode &attentionB)
{
    strcpy(attentionB->name,bpointer->name);
	strcpy(attentionB->id,bpointer->id);
	strcpy(attentionB->author,bpointer->author);
    strcpy(attentionB->publisher,bpointer->publisher);
	for(int i=0;i<3;i++)
		attentionB->boughtTime[i]=bpointer->boughtTime[i];
	attentionB->number=bpointer->number;
    strcpy(attentionB->description,bpointer->description);
	attentionB->limit=bpointer->limit;
	attentionB->isBorrowed=bpointer->isBorrowed;
	if(attentionB->isBorrowed)
		attentionB->borrower=bpointer->borrower;
	attentionB->reserveNumber=bpointer->reserveNumber;
	if(0!=attentionB->reserveNumber)
	{
        initQueue2(&attentionB->reserveQueue);
		attentionB->reserveQueue.front=bpointer->reserveQueue.front;
		for(int i=0;i<attentionB->reserveNumber;i++)
            attentionB->reserveQueue.base[(attentionB->reserveQueue.front+i)%MAXRNUM]=bpointer->reserveQueue.base[(bpointer->reserveQueue.front+i)%MAXRNUM];
    }
}

void initQueue2(SqQueue * Q)
{
	Q->base=(int*)malloc(MAXRNUM*sizeof(int));
	Q->front=Q->rear=0;
}
