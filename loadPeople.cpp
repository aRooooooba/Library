#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "dataStruct.h"
#include "functions.h"

void loadPeople()
{
	FILE * peopleFile;
    peopleNUM=0;
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
        else
            ppointer2->academy[0]='\0';
        fscanf(peopleFile,"%d%d",&ppointer2->credit,&ppointer2->borrowNumber);
        borrowedBookNode BR_Bpointer1=NULL,BR_Bpointer2=NULL;
        ppointer2->bookBorrowed=(borrowedBookNode)malloc(sizeof(borrowedBook));
        ppointer2->bookBorrowed->nextBB=NULL;
        BR_Bpointer1=ppointer2->bookBorrowed;
        for(int i=0;i<ppointer2->borrowNumber;i++)
        {
            fgetc(peopleFile);
            BR_Bpointer2=(borrowedBookNode)malloc(sizeof(borrowedBook));
            BR_Bpointer2->nextBB=NULL;
            fgets(BR_Bpointer2->id,17,peopleFile);
            BR_Bpointer2->id[16]='\0';
            for(int j=0;j<3;j++)
                fscanf(peopleFile,"%d",&BR_Bpointer2->returnTime[j]);
            BR_Bpointer1->nextBB=BR_Bpointer2;
            BR_Bpointer1=BR_Bpointer2;
        }
        ppointer2->borrowedBTail=BR_Bpointer1;
        fscanf(peopleFile,"%d",&ppointer2->reserveNumber);
        BR_Bpointer1=NULL,BR_Bpointer2=NULL;
        ppointer2->bookReserved=(borrowedBookNode)malloc(sizeof(borrowedBook));
        ppointer2->bookReserved->nextBB=NULL;
        BR_Bpointer1=ppointer2->bookReserved;
        for(int i=0;i<ppointer2->reserveNumber;i++)
        {
            fgetc(peopleFile);
            BR_Bpointer2=(borrowedBookNode)malloc(sizeof(borrowedBook));
            BR_Bpointer2->nextBB=NULL;
            fgets(BR_Bpointer2->id,17,peopleFile);
            BR_Bpointer2->id[16]='\0';
            BR_Bpointer1->nextBB=BR_Bpointer2;
            BR_Bpointer1=BR_Bpointer2;
        }
        ppointer2->reservedBTail=BR_Bpointer1;
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
