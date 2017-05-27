#include <cstdio>
#include <cstdlib>
#include "dataStruct.h"
#include "functions.h"

void savePeople(int chooseFree)
{
	FILE * peopleFile;
    personNode ppointer1=NULL,ppointer2=peopleHead->nextPerson;
    peopleFile=fopen("D:\\Library\\peopleFile.txt","w");
    while(ppointer2)
    {
    	ppointer1=ppointer2;
		fputs(ppointer1->name,peopleFile);
		fprintf(peopleFile,"%d\n%d\n",ppointer1->job,ppointer1->id);
		fprintf(peopleFile,"%s\n",ppointer1->password);
		if(student==ppointer1->job)
			fputs(ppointer1->academy,peopleFile);
        fprintf(peopleFile,"%d\n",ppointer1->credit);
        fprintf(peopleFile,"%d %d %d\n",ppointer1->borrowNumber,ppointer1->borrowTimes,ppointer1->returnOnTime);
        borrowedBookNode bpointer=ppointer1->bookBorrowed->nextBB;
        if(0==chooseFree)
            while(bpointer)
            {
                fputs(bpointer->id,peopleFile);
                fprintf(peopleFile,"\n");
                for(int i=0;i<2;i++)
                    fprintf(peopleFile,"%d ",bpointer->returnTime[i]);
                fprintf(peopleFile,"%d",bpointer->returnTime[2]);
                fprintf(peopleFile,"\n");
                bpointer=bpointer->nextBB;
            }
        else
        {
            while(bpointer)
            {
                fputs(bpointer->id,peopleFile);
                fprintf(peopleFile,"\n");
                for(int i=0;i<2;i++)
                    fprintf(peopleFile,"%d ",bpointer->returnTime[i]);
                fprintf(peopleFile,"%d",bpointer->returnTime[2]);
                fprintf(peopleFile,"\n");
                free(ppointer1->bookBorrowed);
                ppointer1->bookBorrowed=bpointer;
                bpointer=bpointer->nextBB;
            }
            free(ppointer1->bookBorrowed);
        }
        fprintf(peopleFile,"%d %d\n",ppointer1->reserveNumber,ppointer1->reserveTimes);
        bpointer=ppointer1->bookReserved->nextBB;
        if(0==chooseFree)
            while(bpointer)
            {
                fputs(bpointer->id,peopleFile);
                fprintf(peopleFile,"\n");
                bpointer=bpointer->nextBB;
            }
        else
            while(bpointer)
            {
                fputs(bpointer->id,peopleFile);
                fprintf(peopleFile,"\n");
                free(ppointer1->bookReserved);
                ppointer1->bookReserved=bpointer;
                bpointer=bpointer->nextBB;
            }
        ppointer2=ppointer1->nextPerson;
        if(1==chooseFree)
            free(ppointer1);
	}
	fprintf(peopleFile,"#");
    fprintf(peopleFile,"\n%s\n",administrator->username);
    fprintf(peopleFile,"%s\n",administrator->password);
    fprintf(peopleFile,"%s",administrator->key);
    fclose(peopleFile);
}
