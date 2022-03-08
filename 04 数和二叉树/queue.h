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

typedef int TElemType;
typedef struct BiNode //二叉链表
{
	TElemType data;
	struct BiNode* lchild, * rchild; //左右孩子指针
}BiNode, * BiTree;

typedef BiNode* QElemType;
typedef QElemType BTNode; //也可用这种方式定义

#define MAXQSIZE 8

typedef struct
{
	QElemType* base;	//动态分配存储空间
	int front;			//头指针 - 若队列不空 指向队列头元素
	int rear;			//尾指针 表示队尾元素的下标 - 若队列不空 指向队列尾元素的下一个位置
}SqQueue;


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
