#include <cstdio>
#include <cstdlib>
#include "dataStruct.h"
#include "functions.h"

void saveBook(int chooseFree)
{
    int MAXRNUM=10;
    FILE * bookFile;
    bookNode bpointer1=NULL,bpointer2=bookHead->nextBook;
    bookFile=fopen("D:\\Library\\bookFile.txt","w");
    while(bpointer2)
    {
        bpointer1=bpointer2;
        fputs(bpointer1->name,bookFile);
        fputs(bpointer1->id,bookFile);
        fprintf(bookFile,"\n");
		fputs(bpointer1->author,bookFile);
		fputs(bpointer1->publisher,bookFile);
		for(int i=0;i<2;i++)
			fprintf(bookFile,"%d ",bpointer1->boughtTime[i]);
        fprintf(bookFile,"%d\n",bpointer1->boughtTime[2]);
        for(int i=0;i<2;i++)
            fprintf(bookFile,"%d ",bpointer1->returnTime[i]);
        fprintf(bookFile,"%d\n%d\n",bpointer1->returnTime[2],bpointer1->number);
		fputs(bpointer1->description,bookFile);
        fprintf(bookFile,"%d %d\n",bpointer1->limit,bpointer1->isBorrowed);
        if(bpointer1->isBorrowed)
            fprintf(bookFile,"%d\n",bpointer1->borrower);
        fprintf(bookFile,"%d\n",bpointer1->reserveNumber);
        for(int i=0;i<bpointer1->reserveNumber;i++)
            fprintf(bookFile,"%d\n",bpointer1->reserveQueue.base[(bpointer1->reserveQueue.front+i)%MAXRNUM]);
        if(1==chooseFree)
            free(bpointer1->reserveQueue.base);
        bpointer2=bpointer1->nextBook;
        if(1==chooseFree)
            free(bpointer1);
	}
	fprintf(bookFile,"#");
	fclose(bookFile);
}
