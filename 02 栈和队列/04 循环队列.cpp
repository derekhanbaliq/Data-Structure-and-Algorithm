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

int main(void)
{


	return 0;
}
