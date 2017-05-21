#ifndef DATASTRUCT_H
#define DATASTRUCT_H

typedef int status;

typedef struct 
{
	int * base;	//��ʼ���Ķ�̬����洢�ռ䣬�洢������
	int front;	//ͷָ��
	int rear;	//βָ�룬�����в��գ�ָ��βԪ�ص���һ��λ��
}SqQueue;

typedef struct bookType
{
	char name[16*20];	//���������20����
    char id[17];
    //ͼ���ţ�[0,1,2,3,4,5,6,7][8,9][10,11][12,13][14,15]�ֱ���������ڡ���������ĸ��š�����������ĸ��š�������������ĸ��š����������ţ����һλ���'\0'
	char author[16*4];	//�������֣����4����
	char publisher[16*10];	//���������֣����10����
	int boughtTime[3];	//�������ڣ�[0][1][2]�ֱ�Ϊ������
    int returnTime[3];
	int number;	//���������
	char description[16*30];	//��飬30������
	status limit;	//1Ϊֻ����ʦ�ܿ���0���ܿ�
	status isBorrowed;	//1���ڽ�״̬
    int borrower;   //�����߱��
	int reserveNumber;	//ԤԼ����
	SqQueue reserveQueue;	//ԤԼ����
	struct bookType * nextBook;
}book,* bookNode;

typedef struct borrowedBookType
{
    char id[17];	//ͬ��ͼ����
	int returnTime[3];	//�黹���ڣ��������ԤԼ״̬���򲻱���д
	struct borrowedBookType * nextBB;
}borrowedBook,* borrowedBookNode;

typedef struct personType
{
	char name[16*4];	//���������4����
	status job;	//������ѧ������ʦ
	int id;	//ѧ��ѧ�Ż��ʦ�����ţ���һ�����ʹ洢
    char password[12];	//���룬���12λ
	char academy[16*15];	//ѧԺ�������15����
	int credit;	//���ã�����100
	int borrowNumber;	//��������
	borrowedBookNode bookBorrowed;
	borrowedBookNode borrowedBTail;	//β��㣬�������
	int reserveNumber;	//ԤԼ����
	borrowedBookNode bookReserved;
	borrowedBookNode reservedBTail;
	struct personType * nextPerson;
}person,* personNode;

typedef struct timeType
{
    int year;
    int month;
    int day;
}* time;

#endif	//DATASTRUCT_H

