#include <iostream>

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


int main(void)
{
	BiTree bt;



	return 0;
}
