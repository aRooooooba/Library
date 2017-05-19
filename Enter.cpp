#include "functions.h"
#include <cstring>

char * appendEnter(char * Source)
{
    strcpy(CEnter,Source);
    int i=strlen(CEnter);
    CEnter[i]='\n';
    CEnter[i+1]='\0';
    return CEnter;
}

char * removeEnter(char * Source)
{
    strcpy(CEnter,Source);
    int i=strlen(CEnter);
    CEnter[i-1]='\0';
    return CEnter;
}
