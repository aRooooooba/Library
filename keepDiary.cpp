#include "dataStruct.h"
#include "functions.h"
#include <cstdio>

void keepDiary(personNode ppointer,bookNode bpointer,int choose)
{
    FILE * diaryFile=fopen("D:\\Library\\diaryFile.txt","a");
    if(loginP==choose)
    {
        fprintf(diaryFile,"\n%d��%d��%d��,",date->year,date->month,date->day);
        if(!ppointer)
            fprintf(diaryFile,"����Ա��¼��ϵͳ��\n");
        else
        {
            if(student==ppointer->job)
                fprintf(diaryFile,"%sͬѧ",removeEnter(ppointer->name));
            else
                fprintf(diaryFile,"%s��ʦ",removeEnter(ppointer->name));
            fprintf(diaryFile,"(ID:%d)��¼��ϵͳ��\n",ppointer->id);
        }
    }
    else if(borrowB==choose)
        fprintf(diaryFile,"�ö��߽����ˡ�%s��(ID:%s)һ�顣\n",removeEnter(bpointer->name),bpointer->id);
    else if(reserveB==choose)
        fprintf(diaryFile,"�ö���ԤԼ�ˡ�%s��(ID:%s)һ�顣\n",removeEnter(bpointer->name),bpointer->id);
    else if(returnB==choose)
        fprintf(diaryFile,"�ö��߹黹�ˡ�%s��(ID:%s)һ�顣\n",removeEnter(bpointer->name),bpointer->id);
    else if(noReserveB==choose)
        fprintf(diaryFile,"�ö���ȡ���˶ԡ�%s��(ID:%s)һ���ԤԼ��\n",removeEnter(bpointer->name),bpointer->id);
    else if(noReserveB_auto==choose)
    {
        fprintf(diaryFile,"\n%d��%d��%d��,",date->year,date->month,date->day);
        if(student==ppointer->job)
            fprintf(diaryFile,"%sͬѧ",removeEnter(ppointer->name));
        else
            fprintf(diaryFile,"%s��ʦ",removeEnter(ppointer->name));
        fprintf(diaryFile,"ԤԼ���ڣ�ϵͳ�Զ�ȡ������ԡ�%s��(ID:%s)һ���ԤԼ��\n",removeEnter(bpointer->name),bpointer->id);
    }
    else if(addP==choose)
    {
        fprintf(diaryFile,"%d��%d��%d��,",date->year,date->month,date->day);
        fprintf(diaryFile,"ͼ���������һλ���ߣ�������%s��ID��%d\n",removeEnter(ppointer->name),ppointer->id);
    }
    else if(addB==choose)
    {
        fprintf(diaryFile,"%d��%d��%d��,",date->year,date->month,date->day);
        fprintf(diaryFile,"ͼ���������һ���飬������%s����ID��%s\n",removeEnter(bpointer->name),bpointer->id);
    }
    fclose(diaryFile);
}
