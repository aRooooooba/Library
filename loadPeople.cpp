#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "dataStruct.h"
#include "functions.h"

void freeWarning();

void loadPeople()
{
    freeWarning();
	FILE * peopleFile;
    peopleNUM=0;
    peopleHead=(personNode)malloc(sizeof(person));
    peopleHead->nextPerson=NULL;
    personNode ppointer1=peopleHead,ppointer2=NULL;
    peopleFile=fopen("D:\\Library\\peopleFile.txt","r");
	ppointer2=(personNode)malloc(sizeof(person));
	ppointer2->nextPerson=NULL;
    borrowerWarningNode WBpointer1=warningBorrower,WBpointer2=NULL;
    reserverAlertNode RApointer1=alertReserver,RApointer2=NULL;
	while(1)
	{
		fgets(ppointer2->name,64,peopleFile);
		if('#'==ppointer2->name[0])	//�ļ�����
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
            int diffDay=GetDiffDays(date->year,date->month,date->day,BR_Bpointer2->returnTime[0],BR_Bpointer2->returnTime[1],BR_Bpointer2->returnTime[2]);
            if(0<diffDay)
            {
                ppointer2->credit-=diffDay;
                WBpointer2=(borrowerWarningNode)malloc(sizeof(borrowerWarningList));
                WBpointer2->nextWarningBorrower=warningBorrower->nextWarningBorrower;
                WBpointer2->personID=ppointer2->id;
                strcpy(WBpointer2->personName,removeEnter(ppointer2->name));
                WBpointer2->job=ppointer2->job;
                WBpointer2->diffDays=diffDay;
                strcpy(WBpointer2->bookID,BR_Bpointer2->id);
                bookNode bpointer=bookHead->nextBook;
                for(;0!=strcmp(bpointer->id,BR_Bpointer2->id);bpointer=bpointer->nextBook);
                strcpy(WBpointer2->bookName,removeEnter(bpointer->name));
                warningBorrower->nextWarningBorrower=WBpointer2;
                for(;WBpointer1->nextWarningBorrower;WBpointer1=WBpointer1->nextWarningBorrower);
                BWNUM++;
            }
            else if(-5<diffDay)
            {
                WBpointer2=(borrowerWarningNode)malloc(sizeof(borrowerWarningList));
                WBpointer2->nextWarningBorrower=NULL;
                WBpointer2->personID=ppointer2->id;
                strcpy(WBpointer2->personName,removeEnter(ppointer2->name));
                WBpointer2->job=ppointer2->job;
                WBpointer2->diffDays=diffDay;
                strcpy(WBpointer2->bookID,BR_Bpointer2->id);
                bookNode bpointer=bookHead->nextBook;
                for(;0!=strcmp(bpointer->id,BR_Bpointer2->id);bpointer=bpointer->nextBook);
                strcpy(WBpointer2->bookName,removeEnter(bpointer->name));
                WBpointer1->nextWarningBorrower=WBpointer2;
                WBpointer1=WBpointer1->nextWarningBorrower;
                BWNUM++;
            }
            if(0>ppointer2->credit)
                ppointer2->credit=0;
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
            bookNode bpointer=bookHead->nextBook;
            for(;0!=strcmp(bpointer->id,BR_Bpointer2->id);bpointer=bpointer->nextBook);
            if(0==bpointer->isBorrowed&&bpointer->reserveQueue.base[bpointer->reserveQueue.front]==ppointer2->id)
            {
                RApointer2=(reserverAlertNode)malloc(sizeof(reserverAlertList));
                RApointer2->nextAlertReserver=NULL;
                RApointer2->personID=ppointer2->id;
                strcpy(RApointer2->personName,removeEnter(ppointer2->name));
                RApointer2->job=ppointer2->job;
                strcpy(RApointer2->bookID,bpointer->id);
                strcpy(RApointer2->bookName,removeEnter(bpointer->name));
                RApointer1->nextAlertReserver=RApointer2;
                RApointer1=RApointer1->nextAlertReserver;
                RANUM++;
            }
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
    peopleTail=ppointer1;	//β���
	free(ppointer2);
    fclose(peopleFile);
}

void freeWarning()
{
    borrowerWarningNode WBpointer1=warningBorrower->nextWarningBorrower,WBpointer2=NULL;
    while(WBpointer1)
    {
        WBpointer2=WBpointer1->nextWarningBorrower;
        free(WBpointer1);
        WBpointer1=WBpointer2;
    }
    warningBorrower->nextWarningBorrower=NULL;
    BWNUM=0;
    reserverAlertNode RApointer1=alertReserver->nextAlertReserver,RApointer2=NULL;
    while(RApointer1)
    {
        RApointer2=RApointer1->nextAlertReserver;
        free(RApointer1);
        RApointer1=RApointer2;
    }
    alertReserver->nextAlertReserver=NULL;
    RANUM=0;
}
