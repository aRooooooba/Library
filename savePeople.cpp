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
		fprintf(peopleFile,"%d\n%d\n",ppointer1->credit,ppointer1->borrowNumber);
		if(0!=ppointer1->borrowNumber)
		{
            borrowedBookNode bpointer=ppointer1->bookBorrowed->nextBB;
            if(0==chooseFree)
                while(bpointer)
                {
                    fputs(bpointer->id,peopleFile);
                    fprintf(peopleFile,"\n");
                    for(int i=0;i<3;i++)
                        fprintf(peopleFile,"%d ",bpointer->returnTime[i]);
                    fprintf(peopleFile,"\n");
                    bpointer=bpointer->nextBB;
                }
            else
                while(ppointer1->bookBorrowed)
                {
                    for(int i=0;i<16;i++)
                        fprintf(peopleFile,"%d ",bpointer->id[i]);
                    fprintf(peopleFile,"\n");
                    for(int i=0;i<3;i++)
                        fprintf(peopleFile,"%d ",bpointer->returnTime[i]);
                    fprintf(peopleFile,"\n");
                    ppointer1->bookBorrowed=bpointer->nextBB;
                    free(bpointer);
                    bpointer=ppointer1->bookBorrowed;
                }
		}
		fprintf(peopleFile,"%d\n",ppointer1->reserveNumber);
		if(0!=ppointer1->reserveNumber)
		{
            borrowedBookNode bpointer=ppointer1->bookReserved->nextBB;
            if(0==chooseFree)
                while(bpointer)
                {
                    fputs(bpointer->id,peopleFile);
                    fprintf(peopleFile,"\n");
                    bpointer=bpointer->nextBB;
                }
            else
                while(ppointer1->bookReserved)
                {
                    for(int i=0;i<16;i++)
                        fprintf(peopleFile,"%d ",bpointer->id[i]);
                    fprintf(peopleFile,"\n");
                    ppointer1->bookReserved=bpointer->nextBB;
                    free(bpointer);
                    bpointer=ppointer1->bookReserved;
                }
		}
        ppointer2=ppointer1->nextPerson;
        if(1==chooseFree)
            free(ppointer1);
	}
	fprintf(peopleFile,"#");
    fclose(peopleFile);
}
