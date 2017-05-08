#include <cstdio>
#include <cstdlib>
#include "dataStruct.h"
#include "copyinfob.h"

extern bookNode bookHead,bookTail;
extern int bookNUM,MAXRNUM;

void initQueue1(SqQueue * Q);
void enQueue(SqQueue * Q,int reserveid);

void loadBook()
{
	FILE * bookFile;
	bookNode bpointer1=bookHead,bpointer2=NULL;
    bookFile=fopen("C:\\Users\\aRooba\\Desktop\\Library\\bookFile.txt","r");
    if(bookFile)
	{
		bpointer2=(bookNode)malloc(sizeof(book));
		bpointer2->nextBook=NULL;
		while(1)
		{
			fgets(bpointer2->name,320,bookFile);
            if('#'==bpointer2->name[0])
	            break;
	        fgets(bpointer2->id,17,bookFile);
	        fgetc(bookFile);
			fgets(bpointer2->author,64,bookFile);
			fgets(bpointer2->publisher,160,bookFile);
			for(int i=0;i<3;i++)
				fscanf(bookFile,"%d",&bpointer2->boughtTime[i]);
			fscanf(bookFile,"%d",&bpointer2->number);
			fgetc(bookFile);
			fgets(bpointer2->description,480,bookFile);
			fscanf(bookFile,"%d",&bpointer2->limit);
			fscanf(bookFile,"%d",&bpointer2->isBorrowed);
	        if(bpointer2->isBorrowed)
	            fscanf(bookFile,"%d",&bpointer2->borrower);
			fscanf(bookFile,"%d",&bpointer2->reserveNumber);
			if(0!=bpointer2->reserveNumber)
			{
                initQueue1(&bpointer2->reserveQueue);
				int reserveid;
				for(int i=0;i<bpointer2->reserveNumber;i++)
				{
					fscanf(bookFile,"%d",&reserveid);
					enQueue(&bpointer2->reserveQueue,reserveid);
				}
			}
			bpointer1->nextBook=bpointer2;
			bpointer1=bpointer2;
			bpointer2=(bookNode)malloc(sizeof(book));
			bpointer2->nextBook=NULL;
			fgetc(bookFile);
            bookNUM++;

		}
        copyInfoB(bpointer1,bookTail);
		free(bpointer2);
	    fclose(bookFile);
	}
}

void initQueue1(SqQueue * Q)
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
