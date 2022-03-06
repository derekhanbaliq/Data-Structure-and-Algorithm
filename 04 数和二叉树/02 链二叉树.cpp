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

//递归：函数自己调用自己
//迭代：函数内某段代码实现循环，循环中每一次迭代的结果会作为下一次迭代的初始值
//二叉树先序遍历算法
Status PreOrderTraverse(BiTree T)
{
	if (T == NULL) //空二叉树
	{
		return OK;
	}
	else
	{
		visit(T); //访问根节点
		PreOrderTraverse(T->lchild); //递归遍历左子树
		PreOrderTraverse(T->rchild); //递归遍历右子树
	}
}


int main(void)
{
	BiTree bt;



	return 0;
}
