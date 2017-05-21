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

int GetAbsDays(int year,int month,int day)
{
    int i;
    int month_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int years=year-1;	//因为欲求距离1年1月1日的距离
    int days=years*365+years/4-years/100+years/400;	//求得之前闰年的数量并在天数上进行想加
    if(year%4==0&&year%100!=0||year%400==0)
        month_day[1]++;	//当前年为闰年，二月加1
    for(i=0;i<month-1;i++)
        days+=month_day[i];
    days+=day-1;	//今天应该是不算如天数计数
    return days;
}

int GetDiffDays(int year1,int month1,int day1,int year2,int month2,int day2)
{
    return GetAbsDays(year1,month1,day1)-GetAbsDays(year2,month2,day2);
}

