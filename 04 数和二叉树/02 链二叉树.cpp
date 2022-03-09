#include <iostream>
#include "config.h"
#include "stack.h"
#include "queue.h"

using namespace std;

//�ݹ飺�����Լ������Լ�
//������������ĳ�δ���ʵ��ѭ����ѭ����ÿһ�ε����Ľ������Ϊ��һ�ε����ĳ�ʼֵ

//����T���
void visit(BiNode* T)
{
	cout << T->data << " ";
}

//��������㷨
Status PreOrderTraverse(BiTree T)
{
	if (T == NULL) //�ն�����
	{
		return OK;
	}
	else
	{
		visit(T); //���ʸ����
		PreOrderTraverse(T->lchild); //�ݹ����������
		PreOrderTraverse(T->rchild); //�ݹ����������
	}
}

//��������㷨
Status InOrderTraverse(BiTree T)
{
	if (T == NULL) //�ն�����
	{
		return OK;
	}
	else
	{
		InOrderTraverse(T->lchild); //�ݹ����������
		visit(T); //���ʸ����
		InOrderTraverse(T->rchild); //�ݹ����������
	}
}

//��������㷨
Status PostOrderTraverse(BiTree T)
{
	if (T == NULL) //�ն�����
	{
		return OK;
	}
	else
	{
		PostOrderTraverse(T->lchild); //�ݹ����������
		PostOrderTraverse(T->rchild); //�ݹ����������
		visit(T); //���ʸ����
	}
}

//��������㷨 - ջʵ��
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

//��α����㷨 - �ö���ʵ��
void LevelOrder(QElemType b)
{
	BTNode p;
	SqQueue qu;

	InitQueue(qu); //��ʼ������
	EnQueue(qu, b);	//���ڵ�ָ��������

	while (QueueLength(qu) != 0) //���в�Ϊ��
	{
		DeQueue(qu, p); //���ӽ��p
		cout << p->data << endl; //���ʽ��p
		if (p->lchild != NULL)
		{
			EnQueue(qu, p->lchild); //������ʱ�������
		}
		if (p->rchild != NULL)
		{
			EnQueue(qu, p->rchild); //���Һ���ʱ�������
		}
	}
}

//������������
Status CreateBiTree(BiTree& T)
{
	char ch;
	
	cout << "input BiTree Node data: ";
	cin >> ch;

	if (ch == '#')
	{
		T = NULL;
	}

	else
	{
		if (!(T = new BiNode))
		{
			exit(OVERFLOW);
		}

		T->data = ch; //���ɸ����
		CreateBiTree(T->lchild); //����������
		CreateBiTree(T->rchild); //����������
	}

	return OK;
}


int main(void)
{
	BiTree bt;

	CreateBiTree(bt); //ABC##DE#G##F###

	cout << endl << endl << "PreOrderTraverse" << endl;
	PreOrderTraverse(bt);

	cout << endl << endl << "InOrderTraverse" << endl;
	InOrderTraverse(bt);

	cout << endl << endl << "PostOrderTraverse" << endl;
	PostOrderTraverse(bt);

	cout << endl << endl << "InOrderTraverse_Stack" << endl;
	InOrderTraverse_Stack(bt);

	cout << endl << endl << "LevelOrder" << endl;
	LevelOrder(QElemType(bt));

	return 0;
}
