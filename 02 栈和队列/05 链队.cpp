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
	QueuePtr front;	//��ͷָ��
	QueuePtr rear;	//��βָ��
}LinkQueue;

//����Q�ĳ�ʼ��
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

//����Q������
Status DestroyQueue(LinkQueue& Q)
{
	QueuePtr p;
	
	while (Q.front)
	{
		p = Q.front->next;
		delete Q.front;
		Q.front = p;
	}

	//��ΪQ.rear��û���õ� ������Q.rear���pִ����������
	//Q.rear = Q.front->next;
	//delete Q.front;
	//Q.front = Q.rear;

	return OK;
}

//��ӡ����Q
void PrintQueue(LinkQueue Q)
{
	while (Q.front != Q.rear)
	{
		Q.front = Q.front->next; //frontָ���һ��ָ�Ĳ���data
		cout << Q.front->data << "\t";
	}
	cout << endl << endl;
}

//��Ԫ��e���
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

//����Q�ĳ���
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

//������Q��ͷԪ��
Status GetHead(LinkQueue Q, QElemType& e)
{
	if (Q.front == Q.rear)
	{
		return ERROR;
	}

	e = Q.front->next->data; //ͷ������һλ��

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
