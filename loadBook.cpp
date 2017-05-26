#include <cstdio>
#include <cstdlib>
#include "dataStruct.h"
#include "functions.h"

void loadBook()
{
	FILE * bookFile;
    bookNUM=0;
    bookHead=(bookNode)malloc(sizeof(book));
    bookHead->nextBook=NULL;
	bookNode bpointer1=bookHead,bpointer2=NULL;
    bookFile=fopen("D:\\Library\\bookFile.txt","r");
	bpointer2=(bookNode)malloc(sizeof(book));
	bpointer2->nextBook=NULL;
	while(1)
	{
		fgets(bpointer2->name,320,bookFile);
        if('#'==bpointer2->name[0])
            break;
        fgets(bpointer2->id,17,bookFile);
        bpointer2->id[16]='\0';
        fgetc(bookFile);
		fgets(bpointer2->author,64,bookFile);
		fgets(bpointer2->publisher,160,bookFile);
		for(int i=0;i<3;i++)
			fscanf(bookFile,"%d",&bpointer2->boughtTime[i]);
        for(int i=0;i<3;i++)
            fscanf(bookFile,"%d",&bpointer2->returnTime[i]);
		fscanf(bookFile,"%d",&bpointer2->number);
		fgetc(bookFile);
		fgets(bpointer2->description,480,bookFile);
		fscanf(bookFile,"%d",&bpointer2->limit);
		fscanf(bookFile,"%d",&bpointer2->isBorrowed);
        if(bpointer2->isBorrowed)
            fscanf(bookFile,"%d",&bpointer2->borrower);
        else
            bpointer2->borrower=0;
        fscanf(bookFile,"%d",&bpointer2->reserveNumber);
        initQueue(&bpointer2->reserveQueue);
        int reserveid;
        for(int i=0;i<bpointer2->reserveNumber;i++)
        {
            fscanf(bookFile,"%d",&reserveid);
            enQueue(&bpointer2->reserveQueue,reserveid);
        }
		bpointer1->nextBook=bpointer2;
		bpointer1=bpointer2;
		bpointer2=(bookNode)malloc(sizeof(book));
		bpointer2->nextBook=NULL;
		fgetc(bookFile);
        bookNUM++;
	}
    bookTail=bpointer1;
	free(bpointer2);
    fclose(bookFile);
}
