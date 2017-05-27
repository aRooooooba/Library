#include "dataStruct.h"
#include "functions.h"
#include <cstdio>

void keepDiary(personNode ppointer,bookNode bpointer,int choose)
{
    FILE * diaryFile=fopen("D:\\Library\\diaryFile.txt","a");
    if(loginP==choose)
    {
        fprintf(diaryFile,"\n%d年%d月%d日,",date->year,date->month,date->day);
        if(!ppointer)
            fprintf(diaryFile,"管理员登录了系统。\n");
        else
        {
            if(student==ppointer->job)
                fprintf(diaryFile,"%s同学",removeEnter(ppointer->name));
            else
                fprintf(diaryFile,"%s老师",removeEnter(ppointer->name));
            fprintf(diaryFile,"(ID:%d)登录了系统。\n",ppointer->id);
        }
    }
    else if(borrowB==choose)
        fprintf(diaryFile,"该读者借阅了《%s》(ID:%s)一书。\n",removeEnter(bpointer->name),bpointer->id);
    else if(reserveB==choose)
        fprintf(diaryFile,"该读者预约了《%s》(ID:%s)一书。\n",removeEnter(bpointer->name),bpointer->id);
    else if(returnB==choose)
        fprintf(diaryFile,"该读者归还了《%s》(ID:%s)一书。\n",removeEnter(bpointer->name),bpointer->id);
    else if(noReserveB==choose)
        fprintf(diaryFile,"该读者取消了对《%s》(ID:%s)一书的预约。\n",removeEnter(bpointer->name),bpointer->id);
    else if(noReserveB_auto==choose)
    {
        fprintf(diaryFile,"\n%d年%d月%d日,",date->year,date->month,date->day);
        if(student==ppointer->job)
            fprintf(diaryFile,"%s同学",removeEnter(ppointer->name));
        else
            fprintf(diaryFile,"%s老师",removeEnter(ppointer->name));
        fprintf(diaryFile,"预约到期，系统自动取消了其对《%s》(ID:%s)一书的预约。\n",removeEnter(bpointer->name),bpointer->id);
    }
    else if(addP==choose)
    {
        fprintf(diaryFile,"%d年%d月%d日,",date->year,date->month,date->day);
        fprintf(diaryFile,"图书馆新添了一位读者，姓名：%s，ID：%d\n",removeEnter(ppointer->name),ppointer->id);
    }
    else if(addB==choose)
    {
        fprintf(diaryFile,"%d年%d月%d日,",date->year,date->month,date->day);
        fprintf(diaryFile,"图书馆新添了一本书，书名《%s》，ID：%s\n",removeEnter(bpointer->name),bpointer->id);
    }
    fclose(diaryFile);
}
