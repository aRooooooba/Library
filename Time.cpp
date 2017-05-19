#include "dataStruct.h"
#include "functions.h"
#include <cstdio>

void loadTime()
{
    FILE * timeFile=fopen("D:\\Library\\time.txt","r");
    fscanf(timeFile,"%d %d %d",&date->year,&date->month,&date->day);
    fclose(timeFile);
}

void saveTime()
{
    FILE * timeFile=fopen("D:\\Library\\time.txt","w");
    fprintf(timeFile,"%d %d %d",date->year,date->month,date->day);
    fclose(timeFile);
}

void dateCalculator()
{
    date->day++;
    if(32==date->day&&(1==date->month||3==date->month||5==date->month||7==date->month||8==date->month||10==date->month||12==date->month))
    {
        date->month++;
        if(13==date->month)
        {
            date->month=1;
            date->year++;
        }
        date->day=1;
    }
    else if(31==date->day&&(4==date->month||6==date->month||9==date->month||11==date->month))
    {
        date->month++;
        date->day=1;
    }
    else if(2==date->month)
    {
        if(30==date->day&&((0==date->year%4&&0!=date->year%100)||0==date->year%400))
        {
            date->month++;
            date->day=1;
        }
        else if(29==date->day)
        {
            date->month++;
            date->day=1;
        }
    }
}
