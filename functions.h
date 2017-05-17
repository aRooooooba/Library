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
void initQueue(SqQueue * Q);
void enQueue(SqQueue * Q,int reserveid);
void dateCalculator();
void appendEnter(char * Source);
void removeEnter(char * Source);

extern personNode peopleHead,peopleTail,attentionP;
extern bookNode bookHead,bookTail,attentionB;
extern int teacher,student,theUser,reader,administrator,bookNUM,peopleNUM,MAXRNUM;
extern time date;
extern char CEnter[500];

#endif // FUNCTIONS

