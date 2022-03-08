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
typedef struct BiNode //��������
{
	TElemType data;
	struct BiNode* lchild, * rchild; //���Һ���ָ��
}BiNode, * BiTree;

typedef BiNode* QElemType;
typedef QElemType BTNode; //Ҳ�������ַ�ʽ����

#define MAXQSIZE 8

typedef struct
{
	QElemType* base;	//��̬����洢�ռ�
	int front;			//ͷָ�� - �����в��� ָ�����ͷԪ��
	int rear;			//βָ�� ��ʾ��βԪ�ص��±� - �����в��� ָ�����βԪ�ص���һ��λ��
}SqQueue;


//��ʼ������Q
Status InitQueue(SqQueue& Q);

//�����Q�ĳ���
int QueueLength(SqQueue Q);

//ѭ������Q���
Status EnQueue(SqQueue& Q, QElemType e);

//ѭ������Q����
Status DeQueue(SqQueue& Q, QElemType& e);

//��ӡ����Q
void PrintQueue(SqQueue Q);

//ȡQ��ͷԪ��
QElemType GetHead(SqQueue Q);
