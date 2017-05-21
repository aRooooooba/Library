#include "functions.h"
#include "dataStruct.h"
#include <cstdio>
#include <cstdlib>

time date=(time)malloc(sizeof(struct timeType));
int teacher=1,student=0,reader=0,administrator=1,bookNUM=0,peopleNUM=0,MAXRNUM=100,theUser,stopTimer=0,oneDayNewBook=1;
personNode peopleHead=NULL,peopleTail=NULL,attentionP=NULL;
bookNode bookHead=NULL,bookTail=NULL,attentionB=NULL;
char CEnter[500];
