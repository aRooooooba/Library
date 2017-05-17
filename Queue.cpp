#include "dataStruct.h"
#include "functions.h"
#include <cstdlib>

void initQueue(SqQueue * Q)
{
	Q->base=(int*)malloc(MAXRNUM*sizeof(int));
	Q->front=Q->rear=0;
}

void enQueue(SqQueue * Q,int reserveid)
{
    if((Q->rear+1)%MAXRNUM==Q->front)
		exit(0);
	Q->base[Q->rear]=reserveid;
	Q->rear=(Q->rear+1)%MAXRNUM;
}
