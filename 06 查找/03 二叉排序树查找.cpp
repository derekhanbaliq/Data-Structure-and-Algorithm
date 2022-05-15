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

//数据元素类型定义
typedef struct
{
	KeyType key; //关键字域
	InfoType otherinfo; //其他数据域
} ElemType;

//二叉排序树结构类型定义
typedef struct BSTNode //若用 *BSTree 必须加该处的BSTNode!
{
	ElemType data; //数据域
	struct BSTNode* lchild, * rchild; //左右孩子指针
}BSTNode, * BSTree;

BSTree T; //定义二叉排序树T

BSTree SearchBST(BSTree T, KeyType key)
{
	if ((!T) || key == T->data.key)
	{
		return T;
	}
	else if (key < T->data.key)
	{
		return SearchBST(T->lchild, key); //在左子树中继续查找
	}
	else
	{
		return SearchBST(T->rchild, key); //在左子树中继续查找
	}
}

int main(void)
{


	return 0;
}
