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

typedef struct BiNode //二叉链表
{
	TElemType data;
	struct BiNode* lchild, * rchild; //左右孩子指针
}BiNode, *BiTree;

typedef struct TriNode //三叉链表
{
	TElemType data;
	struct BiNode* lchild, * parent, * rchild;
}TriNode, * TryTree;

int main02(void)
{
	BiTree bt;



	return 0;
}
