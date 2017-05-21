#include <cstdlib>
#include <cstring>
#include "dataStruct.h"
#include "functions.h"

int Kmp(const char text[], const char find[]);

int searchPeople(personNode &searchPHead,int index,char input[])
{
	int d=0;
	searchPHead=(personNode)malloc(sizeof(person));
	searchPHead->nextPerson=NULL;
	personNode ppointer=peopleHead->nextPerson,ppointer1=searchPHead,ppointer2=NULL;
	if(0==index)
		while(ppointer)
		{
			if(1==Kmp(ppointer->name,input))//对人逐个访问比较
			{
				ppointer2=(personNode)malloc(sizeof(person));
				ppointer2->nextPerson=NULL;
				copyInfoP(ppointer2,ppointer);
				ppointer1->nextPerson=ppointer2;
				ppointer1=ppointer2;
				d++;
			}
			ppointer=ppointer->nextPerson;
		}
	else if(1==index)
	{
		char c[20];
		int sid,i;
	 	while(ppointer)
	 	{
	 		for(sid=ppointer->id,i=0;sid>0;sid/=10,i++)
	 			c[i]=sid%10+'0';
	 		c[i]='\0';
            if(1==Kmp(c,input))//对人逐个访问比较
	 		{
				ppointer2=(personNode)malloc(sizeof(person));
				ppointer2->nextPerson=NULL;
				copyInfoP(ppointer2,ppointer);
				ppointer1->nextPerson=ppointer2;
				ppointer1=ppointer2;
				d++;
			}
			 ppointer=ppointer->nextPerson;
		}
	}
	else if(2==index)
		while(ppointer)
		{
			if(1==Kmp(ppointer->academy,input))//对人逐个访问比较
			{
				ppointer2=(personNode)malloc(sizeof(person));
				ppointer2->nextPerson=NULL;
				copyInfoP(ppointer2,ppointer);
				ppointer1->nextPerson=ppointer2;
				ppointer1=ppointer2;
				d++;
			}
			ppointer=ppointer->nextPerson;
		}
	else if(3==index)
	{
		int j=input[0]-'0';
		while(ppointer)
		{
			if(j==ppointer->job)
			{
				ppointer2=(personNode)malloc(sizeof(person));
				ppointer2->nextPerson=NULL;
				copyInfoP(ppointer2,ppointer);
				ppointer1->nextPerson=ppointer2;
				ppointer1=ppointer2;
				d++;
			}
			ppointer=ppointer->nextPerson;
		}
	}
	return d;
}

int searchBook(bookNode &searchBHead,int index,char input[])
{
	int d=0;
	searchBHead=(bookNode)malloc(sizeof(book));
	searchBHead->nextBook=NULL;
	bookNode bpointer=bookHead->nextBook,bpointer1=searchBHead,bpointer2=NULL; 
	if(0==index)
		while(bpointer)
		{
			if(1==Kmp(bpointer->name,input))//对书籍逐个访问比较 
			{
				bpointer2=(bookNode)malloc(sizeof(book));
				bpointer2->nextBook=NULL;
				copyInfoB(bpointer2,bpointer);
				bpointer1->nextBook=bpointer2;
				bpointer1=bpointer2;
				d++;
			}
			bpointer=bpointer->nextBook;
		}
	else if(1==index)
		while(bpointer)
		{
			if(1==Kmp(bpointer->author,input))//对作者逐个访问比较
			{
				bpointer2=(bookNode)malloc(sizeof(book));
				bpointer2->nextBook=NULL;
				copyInfoB(bpointer2,bpointer);
				bpointer1->nextBook=bpointer2;
				bpointer1=bpointer2;
				d++;
			}
			bpointer=bpointer->nextBook;
		 }
	else if(2==index)
		while(bpointer)
		{
			if(1==Kmp(bpointer->publisher,input))
			{
				bpointer2=(bookNode)malloc(sizeof(book));
				bpointer2->nextBook=NULL;
				copyInfoB(bpointer2,bpointer);
				bpointer1->nextBook=bpointer2;
				bpointer1=bpointer2;
				d++;
			}
			bpointer=bpointer->nextBook;
		}
	else if(3==index)
		while(bpointer)
		{
			if(1==Kmp(bpointer->id,input))//对书籍编号逐个访问比较
			{
				bpointer2=(bookNode)malloc(sizeof(book));
				bpointer2->nextBook=NULL;
				copyInfoB(bpointer2,bpointer);
				bpointer1->nextBook=bpointer2;
				bpointer1=bpointer2;
				d++;
			}
			bpointer=bpointer->nextBook;
		}
	return d;
}

int Kmp(const char text[], const char find[])
{
	int find_len=strlen(find);
	int text_len=strlen(text);
	if(text_len<find_len)
		return 0;
	int map[find_len];
    //initial the Kmp base array: map  
    map[0]=0;  
    map[1]=0;  
    int i=2;
    int j=0;  
    for(i=2;i<find_len;i++)
        while(1)
        {  
            if(find[i-1]==find[j])
            {  
                j++;  
                if(find[i]==find[j])
                    map[i]=map[j];
                else
                    map[i]=j;
                break;  
            }  
            else  
            {  
                if(j==0)  
                {  
                    map[i]=0;  
                    break;  
                }  
                j=map[j];  
            }  
        }
    j=0;  
    for (i=0;i<text_len;)  
    {  
        if(text[i]==find[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            j=map[j];  
            if(j==0)  
                i++;  
        }  
        if(j==(find_len))  
            return 1;  
    }  
    return 0;  
} 
