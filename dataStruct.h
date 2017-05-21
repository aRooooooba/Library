#ifndef DATASTRUCT_H
#define DATASTRUCT_H

typedef int status;

typedef struct 
{
	int * base;	//初始化的动态分配存储空间，存储人物编号
	int front;	//头指针
	int rear;	//尾指针，若队列不空，指向尾元素的下一个位置
}SqQueue;

typedef struct bookType
{
	char name[16*20];	//书名，最大20个字
    char id[17];
    //图书编号，[0,1,2,3,4,5,6,7][8,9][10,11][12,13][14,15]分别代表购入日期、书名首字母编号、作者名首字母编号、出版社名首字母编号、当天新书编号，最后一位存放'\0'
	char author[16*4];	//作者名字，最大4个字
	char publisher[16*10];	//出版社名字，最大10个字
	int boughtTime[3];	//购入日期，[0][1][2]分别为年月日
    int returnTime[3];
	int number;	//该书的数量
	char description[16*30];	//简介，30字以内
	status limit;	//1为只有老师能看，0都能看
	status isBorrowed;	//1是在借状态
    int borrower;   //借书者编号
	int reserveNumber;	//预约人数
	SqQueue reserveQueue;	//预约队列
	struct bookType * nextBook;
}book,* bookNode;

typedef struct borrowedBookType
{
    char id[17];	//同上图书编号
	int returnTime[3];	//归还日期，如果是在预约状态中则不必填写
	struct borrowedBookType * nextBB;
}borrowedBook,* borrowedBookNode;

typedef struct personType
{
	char name[16*4];	//人名，最大4个字
	status job;	//工作，学生或老师
	int id;	//学生学号或教师工作号，用一个整型存储
    char password[12];	//密码，最多12位
	char academy[16*15];	//学院名，最大15个字
	int credit;	//信用，满分100
	int borrowNumber;	//借书数量
	borrowedBookNode bookBorrowed;
	borrowedBookNode borrowedBTail;	//尾结点，便于添加
	int reserveNumber;	//预约数量
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

