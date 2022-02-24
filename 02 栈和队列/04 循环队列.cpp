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
	QElemType* base;	//��̬����洢�ռ�
	int front;			//ͷָ�� - �����в��� ָ�����ͷԪ��
	int rear;			//βָ�� ��ʾ��βԪ�ص��±� - �����в��� ָ�����βԪ�ص���һ��λ��
}SqQueue;

//��ʼ������Q
Status InitQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE]; //��������ռ�
	//Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base) //�洢����ʧ��
	{
		exit(OVERFLOW);
	}

	Q.front = Q.rear = 0; //ͷָ��βָ����Ϊ0 ����Ϊ��
}

//�����Q�ĳ���
int QueueLength(SqQueue Q)
{
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

//ѭ������Q���
Status EnQueue(SqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front) //���� - ���õ������һλ����Ԫ�صķ���
	{
		return ERROR;
	}

	Q.base[Q.rear] = e; //��Ԫ�ؼ����β
	Q.rear = (Q.rear + 1) % MAXQSIZE; //��βָ��+1

	return OK;
}

//ѭ������Q����
Status DeQueue(SqQueue& Q, QElemType& e)
{
	if (Q.front == Q.rear) //�ӿ�
	{
		return ERROR;
	}

	e = Q.base[Q.front]; //�����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE; //��ͷָ��+1

	return OK;
}

//��ӡ����Q
void PrintQueue(SqQueue Q)
{
	for (int i = 0; i < QueueLength(Q); i++)
	{
		cout << Q.base[Q.front + i] << "\t";
	}
	cout << endl << endl;
}

//ȡQ��ͷԪ��
QElemType GetHead(SqQueue Q)
{
	if (Q.front != Q.rear) //���в�Ϊ��
	{
		return Q.base[Q.front]; //���ض�ͷָ��Ԫ�ص�ֵ ��ͷָ�벻��
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
