#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "dataStruct.h"
#include "functions.h"

void loadPeople()
{
	FILE * peopleFile;
    peopleHead=(personNode)malloc(sizeof(person));
    peopleHead->nextPerson=NULL;
    personNode ppointer1=peopleHead,ppointer2=NULL;
    peopleFile=fopen("D:\\Library\\peopleFile.txt","r");
	ppointer2=(personNode)malloc(sizeof(person));
	ppointer2->nextPerson=NULL;
	while(1)
	{
		fgets(ppointer2->name,64,peopleFile);
		if('#'==ppointer2->name[0])	//文件结束
			break;
		fscanf(peopleFile,"%d%d",&ppointer2->job,&ppointer2->id);
        fgetc(peopleFile);
        fscanf(peopleFile,"%s",ppointer2->password);
        fgetc(peopleFile);
		if(student==ppointer2->job)
			fgets(ppointer2->academy,240,peopleFile);
		fscanf(peopleFile,"%d%d",&ppointer2->credit,&ppointer2->borrowNumber);
        if(ppointer2->borrowNumber)
		{
            borrowedBookNode bpointer1=NULL,bpointer2=NULL;
			ppointer2->bookBorrowed=(borrowedBookNode)malloc(sizeof(borrowedBook));
			ppointer2->bookBorrowed->nextBB=NULL;
			bpointer1=ppointer2->bookBorrowed;
			for(int i=0;i<ppointer2->borrowNumber;i++)
			{
				bpointer2=(borrowedBookNode)malloc(sizeof(borrowedBook));
				for(int j=0;j<16;j++)
                    bpointer2->id[j]=fgetc(peopleFile);
				for(int j=0;j<3;j++)
					fscanf(peopleFile,"%d",&bpointer2->returnTime[j]);
				bpointer2->nextBB=NULL;
				bpointer1->nextBB=bpointer2;
				bpointer1=bpointer2;
			}
			ppointer2->borrowedBTail=bpointer1;
		}
		fscanf(peopleFile,"%d",&ppointer2->reserveNumber);
		if(0!=ppointer2->reserveNumber)
		{
            borrowedBookNode bpointer1=NULL,bpointer2=NULL;
			ppointer2->bookReserved=(borrowedBookNode)malloc(sizeof(borrowedBook));
			ppointer2->bookReserved->nextBB=NULL;
			bpointer1=ppointer2->bookReserved;
			for(int i=0;i<ppointer2->reserveNumber;i++)
			{
				bpointer2=(borrowedBookNode)malloc(sizeof(borrowedBook));
				for(int j=0;j<16;j++)
                    bpointer2->id[j]=fgetc(peopleFile);
				bpointer2->nextBB=NULL;
				bpointer1->nextBB=bpointer2;
				bpointer1=bpointer2;
			}
			ppointer2->reservedBTail=bpointer1;
        }
        ppointer1->nextPerson=ppointer2;
        ppointer1=ppointer2;
		ppointer2=(personNode)malloc(sizeof(person));
		ppointer2->nextPerson=NULL;
		fgetc(peopleFile);
        peopleNUM++;
	}
    peopleTail=ppointer1;	//尾结点
	free(ppointer2);
    fclose(peopleFile);
}
