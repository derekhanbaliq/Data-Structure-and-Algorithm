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
	QElemType* base;	//��ʼ���Ķ�̬����洢�ռ�
	int front;			//ͷָ��
	int rear;			//βָ��
}SqQueue;

