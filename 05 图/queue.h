#pragma once
#include <iostream>

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

typedef int Status;
typedef int QElemType;

#define MAXQSIZE 8

typedef struct
{
	QElemType* base;	//动态分配存储空间
	int front;			//头指针 - 若队列不空 指向队列头元素
	int rear;			//尾指针 表示队尾元素的下标 - 若队列不空 指向队列尾元素的下一个位置
}SqQueue;

using namespace std;

//初始化队列Q
Status InitQueue(SqQueue& Q);

//求队列Q的长度
int QueueLength(SqQueue Q);

//循环队列Q入队
Status EnQueue(SqQueue& Q, QElemType e);

//循环队列Q出队
Status DeQueue(SqQueue& Q, QElemType& e);

//打印队列Q
void PrintQueue(SqQueue Q);

//取Q队头元素
QElemType GetHead(SqQueue Q);
