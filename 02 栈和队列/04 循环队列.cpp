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

#define MAXQSIZE 20

typedef struct
{
	QElemType* base;	//动态分配存储空间
	int front;			//头指针 - 若队列不空 指向队列头元素
	int rear;			//尾指针 表示队尾元素的下标 - 若队列不空 指向队列尾元素的下一个位置
}SqQueue;

//初始化队列Q
Status InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE]; //分配数组空间
	//Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base) //存储分配失败
	{
		exit(OVERFLOW);
	}

	Q.front = Q.rear = 0; //头指针尾指针置为0 队列为空
}

//求队列Q的长度
int QueueLength(SqQueue Q)
{
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

int main(void)
{


	return 0;
}
