#include "functions.h"
#include "dataStruct.h"
#include <cstdio>
#include <cstdlib>

time date=(time)malloc(sizeof(struct timeType));
int teacher=1,student=0,reader=0,admini=1,bookNUM=0,peopleNUM=0,MAXRNUM=100,theUser,stopTimer=0,oneDayNewBook=1,BWNUM=0,RANUM=1;
int loginP=1,borrowB=2,reserveB=3,returnB=4,noReserveB=5,noReserveB_auto=6,addP=7,addB=8;
personNode peopleHead=NULL,peopleTail=NULL,attentionP=NULL;
bookNode bookHead=NULL,bookTail=NULL,attentionB=NULL;
borrowerWarningNode warningBorrower=(borrowerWarningNode)malloc(sizeof(borrowerWarningList));
reserverAlertNode alertReserver=(reserverAlertNode)malloc(sizeof(reserverAlertList));
administratorNode administrator=NULL;
char CEnter[500];
