#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "dataStruct.h"
#include "functions.h"

void freeWarning();

void WarnAlert()
{
    freeWarning();
    personNode ppointer=peopleHead->nextPerson;
    borrowerWarningNode WBpointer1=warningBorrower,WBpointer2=NULL;
    reserverAlertNode RApointer1=alertReserver,RApointer2=NULL;
    borrowedBookNode BR_Bpointer1=NULL,BR_Bpointer2=NULL;
    bookNode bpointer=bookHead->nextBook;
    for(;bpointer;bpointer=bpointer->nextBook)
    {
        int diffDay=GetDiffDays(date->year,date->month,date->day,bpointer->returnTime[0],bpointer->returnTime[1],bpointer->returnTime[2]);
        if(0<bpointer->reserveNumber&&2==diffDay)
        {
            bpointer->reserveNumber--;
            bpointer->reserveQueue.front=(bpointer->reserveQueue.front+1)%MAXRNUM;
            bpointer->returnTime[0]=date->year;
            bpointer->returnTime[1]=date->month;
            bpointer->returnTime[2]=date->day;
        }
    }
	while(ppointer)
	{
        BR_Bpointer2=ppointer->bookBorrowed->nextBB;
        for(int i=0;i<ppointer->borrowNumber;i++,BR_Bpointer2=BR_Bpointer2->nextBB)
        {
            int diffDay=GetDiffDays(date->year,date->month,date->day,BR_Bpointer2->returnTime[0],BR_Bpointer2->returnTime[1],BR_Bpointer2->returnTime[2]);
            if(0<diffDay)
            {
                ppointer->credit-=diffDay;
                WBpointer2=(borrowerWarningNode)malloc(sizeof(borrowerWarningList));
                WBpointer2->nextWarningBorrower=warningBorrower->nextWarningBorrower;
                WBpointer2->personID=ppointer->id;
                strcpy(WBpointer2->personName,removeEnter(ppointer->name));
                WBpointer2->job=ppointer->job;
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
                WBpointer2->personID=ppointer->id;
                strcpy(WBpointer2->personName,removeEnter(ppointer->name));
                WBpointer2->job=ppointer->job;
                WBpointer2->diffDays=diffDay;
                strcpy(WBpointer2->bookID,BR_Bpointer2->id);
                bookNode bpointer=bookHead->nextBook;
                for(;0!=strcmp(bpointer->id,BR_Bpointer2->id);bpointer=bpointer->nextBook);
                strcpy(WBpointer2->bookName,removeEnter(bpointer->name));
                WBpointer1->nextWarningBorrower=WBpointer2;
                WBpointer1=WBpointer1->nextWarningBorrower;
                BWNUM++;
            }
            if(0>ppointer->credit)
                ppointer->credit=0;
        }
        BR_Bpointer1=ppointer->bookReserved;
        BR_Bpointer2=ppointer->bookReserved->nextBB;
        for(int i=0;i<ppointer->reserveNumber;i++,BR_Bpointer1=BR_Bpointer2,BR_Bpointer2=BR_Bpointer2->nextBB)
        {
            for(bpointer=bookHead->nextBook;0!=strcmp(bpointer->id,BR_Bpointer2->id);bpointer=bpointer->nextBook);
            if(0==bpointer->isBorrowed&&bpointer->reserveQueue.base[bpointer->reserveQueue.front]==ppointer->id)
            {
                RApointer2=(reserverAlertNode)malloc(sizeof(reserverAlertList));
                RApointer2->nextAlertReserver=NULL;
                RApointer2->personID=ppointer->id;
                strcpy(RApointer2->personName,removeEnter(ppointer->name));
                RApointer2->job=ppointer->job;
                strcpy(RApointer2->bookID,bpointer->id);
                strcpy(RApointer2->bookName,removeEnter(bpointer->name));
                RApointer1->nextAlertReserver=RApointer2;
                RApointer1=RApointer1->nextAlertReserver;
                RANUM++;
            }
            else
            {
                int j;
                for(j=0;j<bpointer->reserveNumber;j++)
                    if(bpointer->reserveQueue.base[(bpointer->reserveQueue.front+j)%MAXRNUM]==ppointer->id)
                        break;
                if(bpointer->reserveNumber==j)
                {
                    ppointer->reserveNumber--;
                    BR_Bpointer1->nextBB=BR_Bpointer2->nextBB;
                    free(BR_Bpointer2);
                    BR_Bpointer2=BR_Bpointer1;
                    keepDiary(ppointer,bpointer,noReserveB_auto);
                }
            }
        }
        ppointer->reservedBTail=BR_Bpointer1;
        ppointer=ppointer->nextPerson;
	}
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
