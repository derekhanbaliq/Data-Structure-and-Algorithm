#include <iostream>
#include "stack.h"

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

#define MAXSIZE			100

typedef int TElemType;
typedef int Status;

typedef struct BiNode //��������
{
	TElemType data;
	struct BiNode* lchild, * rchild; //���Һ���ָ��
}BiNode, *BiTree;

typedef struct TriNode //��������
{
	TElemType data;
	struct BiNode* lchild, * parent, * rchild;
}TriNode, * TryTree;

//�ݹ飺�����Լ������Լ�
//������������ĳ�δ���ʵ��ѭ����ѭ����ÿһ�ε����Ľ������Ϊ��һ�ε����ĳ�ʼֵ

//����T���
void visit(BiNode* T)
{
	;
}

//��������������㷨
Status PreOrderTraverse(BiTree T)
{
	if (T == NULL) //�ն�����
	{
		return OK;
	}
	else
	{
		visit(T); //���ʸ��ڵ�
		PreOrderTraverse(T->lchild); //�ݹ����������
		PreOrderTraverse(T->rchild); //�ݹ����������
	}
}

//��������������㷨
Status InOrderTraverse(BiTree T)
{
	if (T == NULL) //�ն�����
	{
		return OK;
	}
	else
	{
		PreOrderTraverse(T->lchild); //�ݹ����������
		visit(T); //���ʸ��ڵ�
		PreOrderTraverse(T->rchild); //�ݹ����������
	}
}

//��������������㷨
Status PostOrderTraverse(BiTree T)
{
	if (T == NULL) //�ն�����
	{
		return OK;
	}
	else
	{
		PreOrderTraverse(T->lchild); //�ݹ����������
		PreOrderTraverse(T->rchild); //�ݹ����������
		visit(T); //���ʸ��ڵ�
	}
}

//��������������㷨 - ջʵ��
Status InOrderTraverse_Stack(BiTree T)
{
	SElemType p, q;
	SqStack S;

	p = SElemType(T);
	InitStack(S);
	
	while (p || !IsStackEmpty(S))
	{
		if (p)
		{
			Push(S, SElemType(p));
			p = p->lchild;
		}
		else
		{
			Pop(S, q);
			cout << "q->data = " << q->data << endl;
			p = (q->rchild);
		}
	}

	return OK;
}

int main(void)
{
	BiTree bt;



	return 0;
}
