#include <iostream>

using namespace std;

//general define
#define TRUE		1
#define FALSE		0
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

typedef int Status;
typedef int KeyType;
typedef int ElemType;
typedef char InfoType;

//����Ԫ�����Ͷ���
typedef struct
{
	KeyType key; //�ؼ�����
	InfoType otherinfo; //����������
} ElemType;

//�����������ṹ���Ͷ���
typedef struct BSTNode //���� *BSTree ����Ӹô���BSTNode!
{
	ElemType data; //������
	struct BSTNode* lchild, * rchild; //���Һ���ָ��
}BSTNode, * BSTree;

BSTree T; //�������������T

BSTree SearchBST(BSTree T, KeyType key)
{
	if ((!T) || key == T->data.key)
	{
		return T;
	}
	else if (key < T->data.key)
	{
		return SearchBST(T->lchild, key); //���������м�������
	}
	else
	{
		return SearchBST(T->rchild, key); //���������м�������
	}
}

int main(void)
{


	return 0;
}
