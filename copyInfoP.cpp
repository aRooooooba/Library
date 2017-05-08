#include <cstring>
#include <cstdlib>
#include "dataStruct.h"

void copyInfoP(personNode ppointer,personNode &attentionP)
{
    strcpy(attentionP->name, ppointer->name);
    attentionP->job=ppointer->job;
    attentionP->id=ppointer->id;
    strcpy(attentionP->password, ppointer->password);
    strcpy(attentionP->academy,ppointer->academy);
    attentionP->credit=ppointer->credit;
    attentionP->borrowNumber=ppointer->borrowNumber;
    if(0<ppointer->borrowNumber)
    {
        borrowedBookNode bpointer1=NULL,bpointer2=NULL,bpointer3=ppointer->bookBorrowed->nextBB;
        attentionP->bookBorrowed=(borrowedBookNode)malloc(sizeof(borrowedBook));
        attentionP->bookBorrowed->nextBB=NULL;
        bpointer1=attentionP->bookBorrowed;
        for(int i=0;i<ppointer->borrowNumber;i++)
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
        attentionP->borrowedBTail=bpointer1;
    }
    attentionP->reserveNumber=ppointer->reserveNumber;
    if(0<ppointer->reserveNumber)
    {
        borrowedBookNode bpointer1=NULL,bpointer2=NULL,bpointer3=ppointer->bookReserved->nextBB;
        attentionP->bookReserved=(borrowedBookNode)malloc(sizeof(borrowedBook));
        attentionP->bookReserved->nextBB=NULL;
        bpointer1=attentionP->bookReserved;
        for(int i=0;i<ppointer->reserveNumber;i++)
        {
            bpointer2=(borrowedBookNode)malloc(sizeof(borrowedBook));
            strcpy(bpointer2->id,bpointer3->id);
            bpointer2->nextBB=NULL;
            bpointer1->nextBB=bpointer2;
            bpointer1=bpointer2;
            bpointer3=bpointer3->nextBB;
        }
        attentionP->reservedBTail=bpointer1;
    }
}
