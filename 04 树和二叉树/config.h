#pragma once
#include <iostream>

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

#define MAXSSIZE 10
#define MAXQSIZE 8

typedef int Status;

//������typedef
typedef char TElemType;
typedef struct BiNode //��������
{
	TElemType data;
	struct BiNode* lchild, * rchild; //���Һ���ָ��
}BiNode, * BiTree;

//������ջtypedef
typedef BiNode* SElemType;
typedef struct
{
	SElemType* base;	//ջ��ָ��
	SElemType* top;		//ջ��ָ��
	int stacksize;		//ջ�����������
}SqStack;

//����������typedef
typedef BiNode* QElemType;
typedef QElemType BTNode; //Ҳ�������ַ�ʽ����
typedef struct
{
	QElemType* base;	//��̬����洢�ռ�
	int front;			//ͷָ�� - �����в��� ָ�����ͷԪ��
	int rear;			//βָ�� ��ʾ��βԪ�ص��±� - �����в��� ָ�����βԪ�ص���һ��λ��
}SqQueue;

//��������typedef
typedef struct TriNode //��������
{
	TElemType data;
	struct BiNode* lchild, * parent, * rchild;
}TriNode, * TriTree;