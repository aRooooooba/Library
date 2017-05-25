#ifndef FUNCTIONS
#define FUNCTIONS

#include "dataStruct.h"

void saveBook(int chooseFree);
void savePeople(int chooseFree);
void copyInfoB(bookNode &Dest,bookNode Source);
void copyInfoP(personNode &Dest,personNode Source);
void loadBook();
void loadPeople();
void loadTime();
void saveTime();
int GetDiffDays(int year1,int month1,int day1,int year2,int month2,int day2);
void initQueue(SqQueue * Q);
void enQueue(SqQueue * Q,int reserveid);
void dateCalculator();
char * appendEnter(char * Source);
char * removeEnter(char * Source);
int getFirstLetter(char * strName);
int searchPeople(personNode &searchPHead,int index,char input[]);
int searchBook(bookNode &searchBHead,int index,char input[]);

extern personNode peopleHead,peopleTail,attentionP;
extern bookNode bookHead,bookTail,attentionB;
extern borrowerWarningNode warningBorrower;
extern reserverAlertNode alertReserver;
extern int teacher,student,theUser,reader,administrator,bookNUM,peopleNUM,MAXRNUM,stopTimer,oneDayNewBook,BWNUM,RANUM;
extern time date;
extern char CEnter[500];

#endif // FUNCTIONS

