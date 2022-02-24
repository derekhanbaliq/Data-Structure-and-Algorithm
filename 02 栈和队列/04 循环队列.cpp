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

//循环队列Q入队
Status EnQueue(SqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //队满 - 采用的是最后一位不放元素的方法
	{
		return ERROR;
	}

	Q.base[Q.rear] = e; //新元素加入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE; //队尾指针+1

	return OK;
}

//循环队列Q出队
Status DeQueue(SqQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear) //队空
	{
		return ERROR;
	}

	e = Q.base[Q.front]; //保存队头元素
	Q.front = (Q.front + 1) % MAXQSIZE; //队头指针+1

	return OK;
}

//打印队列Q
void PrintQueue(SqQueue Q)
{
	for (int i = 0; i < QueueLength(Q); i++)
	{
		cout << Q.base[Q.front + i] << "\t";
	}
	cout << endl << endl;
}

//取Q队头元素
QElemType GetHead(SqQueue Q)
{
	if (Q.front != Q.rear) //队列不为空
	{
		return Q.base[Q.front]; //返回队头指针元素的值 队头指针不变
	}
}

int main04(void)
{
	SqQueue queue;
	Status s;
	QElemType e;

	InitQueue(queue);
	
	for (int i = 0; i < 8; i++)
	{
		s = EnQueue(queue, i + 1);
		cout << "EnQueue = " << s << endl;

		PrintQueue(queue);
	}
	
	DeQueue(queue, e);
	cout << "DeQueue elem = " << e << endl;
	PrintQueue(queue);

	e = GetHead(queue);
	cout << "GetHead elem = " << e << endl << endl;

	return 0;
}
