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

typedef struct Qnode
{
	QElemType data;
	struct Qnode* next;
}Qnode, *QueuePtr;

typedef struct
{
	QueuePtr front;	//队头指针
	QueuePtr rear;	//队尾指针
}LinkQueue;

//链队Q的初始化
Status InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = new Qnode;

	if (!Q.front)
	{
		exit(OVERFLOW);
	}

	Q.front->next = NULL;

	return OK;
}

//链队Q的销毁
Status DestroyQueue(LinkQueue& Q)
{
	QueuePtr p;
	
	while (Q.front)
	{
		p = Q.front->next;
		delete Q.front;
		Q.front = p;
	}

	//因为Q.rear并没有用到 所以用Q.rear替代p执行销毁任务
	//Q.rear = Q.front->next;
	//delete Q.front;
	//Q.front = Q.rear;

	return OK;
}

//打印链队Q
void PrintQueue(LinkQueue Q)
{
	while (Q.front != Q.rear)
	{
		Q.front = Q.front->next; //front指针第一个指的不是data
		cout << Q.front->data << "\t";
	}
	cout << endl << endl;
}

//将元素e入队
Status EnQueue(LinkQueue& Q, QElemType e)
{
	QueuePtr p = new Qnode;

	if (!p)
	{
		exit(OVERFLOW);
	}

	p->data = e;
	p->next = NULL;

	Q.rear->next = p;
	Q.rear = p;

	return OK;
}

//链队Q的出队
Status DeQueue(LinkQueue& Q, QElemType& e)
{
	QueuePtr p = new Qnode;

	if (Q.front == Q.rear)
	{
		return ERROR;
	}

	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;

	if (Q.rear == p)
	{
		Q.rear = Q.front;
	}

	delete p;

	return OK;
}

//求链队Q的头元素
Status GetHead(LinkQueue Q, QElemType& e)
{
	if (Q.front == Q.rear)
	{
		return ERROR;
	}

	e = Q.front->next->data; //头结点的下一位置

	return OK;
}

int main(void)
{
	LinkQueue lq;
	Status s;
	QElemType e;

	s = InitQueue(lq);
	cout << "InitQueue = " << s << endl << endl;
	
	for (int i = 0; i < 6; i++)
	{
		s = EnQueue(lq, i + 1);
		cout << "EnQueue = " << s << endl;
	}
	PrintQueue(lq);

	DeQueue(lq, e);
	cout << "DeQueue element = " << e << endl;
	PrintQueue(lq);

	s = DestroyQueue(lq);
	cout << "DestroyQueue = " << s << endl << endl;

	return 0;
}
