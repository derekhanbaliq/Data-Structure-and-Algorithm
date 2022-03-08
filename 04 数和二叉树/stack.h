#pragma once
#include <iostream>

using namespace std;

//general define
#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

#define MAXSSIZE		20

typedef int Status;

typedef int TElemType;
typedef struct BiNode //��������
{
	TElemType data;
	struct BiNode* lchild, * rchild; //���Һ���ָ��
}BiNode, * BiTree;

typedef BiNode* SElemType;

typedef struct
{
	SElemType* base;	//ջ��ָ��
	SElemType* top;		//ջ��ָ��
	int stacksize;		//ջ�����������
}SqStack;

//˳��ջS�ĳ�ʼ��
Status InitStack(SqStack& S);

//�ж�˳��ջS�Ƿ�Ϊ��
Status IsStackEmpty(SqStack S);

//��ӡ˳��ջS - �Զ��庯��1
void PrintStack(SqStack S);

//���˳��ջS - �Զ��庯��2
Status FillStack(SqStack& S);

//��˳��ջS����
int StackLength(SqStack S);

//���˳��ջS
Status ClearStack(SqStack S);

//����˳��ջS
Status DestroyStack(SqStack& S);

//˳��ջS����ջ
Status Push(SqStack& S, SElemType e);

//˳��ջS�ĳ�ջ
Status Pop(SqStack& S, SElemType& e);
