#include "functions.h"
#include <cstring>

void appendEnter(char * Source)
{
    strcpy(CEnter,Source);
    int i=strlen(CEnter);
    CEnter[i]='\n';
    CEnter[i+1]='\0';
}

void removeEnter(char * Source)
{
    strcpy(CEnter,Source);
    int i=strlen(CEnter);
    CEnter[i-1]='\0';
}
