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

int main02(void)
{
	BiTree bt;



	return 0;
}
