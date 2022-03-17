#include <iostream>
#include "config.h"
#include "stack.h"
#include "queue.h"

using namespace std;

//递归：函数自己调用自己
//迭代：函数内某段代码实现循环，循环中每一次迭代的结果会作为下一次迭代的初始值

//访问T结点
void visit(BiNode* T)
{
	cout << T->data << " ";
}

//先序遍历算法
Status PreOrderTraverse(BiTree T)
{
	if (T == NULL) //空二叉树
	{
		return OK;
	}
	else
	{
		visit(T); //访问根结点
		PreOrderTraverse(T->lchild); //递归遍历左子树
		PreOrderTraverse(T->rchild); //递归遍历右子树
	}
}

//中序遍历算法
Status InOrderTraverse(BiTree T)
{
	if (T == NULL) //空二叉树
	{
		return OK;
	}
	else
	{
		InOrderTraverse(T->lchild); //递归遍历左子树
		visit(T); //访问根结点
		InOrderTraverse(T->rchild); //递归遍历右子树
	}
}

//后序遍历算法
Status PostOrderTraverse(BiTree T)
{
	if (T == NULL) //空二叉树
	{
		return OK;
	}
	else
	{
		PostOrderTraverse(T->lchild); //递归遍历左子树
		PostOrderTraverse(T->rchild); //递归遍历右子树
		visit(T); //访问根结点
	}
}

//中序遍历算法 - 栈实现
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

//层次遍历算法 - 用队列实现
void LevelOrder(QElemType b)
{
	BTNode p;
	SqQueue qu;

	InitQueue(qu); //初始化队列
	EnQueue(qu, b);	//根节点指针进入队列

	while (QueueLength(qu) != 0) //队列不为空
	{
		DeQueue(qu, p); //出队结点p
		cout << p->data << endl; //访问结点p
		if (p->lchild != NULL)
		{
			EnQueue(qu, p->lchild); //有左孩子时将其进队
		}
		if (p->rchild != NULL)
		{
			EnQueue(qu, p->rchild); //有右孩子时将其进队
		}
	}
}

//先序建立二叉树
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

		T->data = ch; //生成根结点
		CreateBiTree(T->lchild); //构造左子树
		CreateBiTree(T->rchild); //构造右子树
	}

	return OK;
}

//复制二叉树
int Copy(BiTree T, BiTree& NewT)
{
	if (T == NULL)
	{
		NewT = NULL;
		return 0;
	}
	else
	{
		NewT = new BiNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}

//计算二叉树深度
int Depth(BiTree T)
{
	int m, n;
	
	if (T == NULL)
	{
		return 0; //如果是空树 则返回0
	}
	else
	{
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		
		if (m > n)
		{
			return m + 1;
		}
		else
		{
			return n + 1;
		}
	}
}

//计算结点总数
int NodeCount(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}

//计算叶子结点数 - 补充算法
int LeaveCount(BiTree T)
{
	int cnt;
	
	if (T == NULL)
	{
		return 0; //如果是空树 返回0
	}
	else if (T->lchild == NULL && T->rchild == NULL)
	{
		return 1; //如果是叶子结点 返回1
	}
	else
	{
		return LeaveCount(T->lchild) + LeaveCount(T->rchild);
	}
}

int main02(void)
{
	BiTree bt, bt2;

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

	cout << endl << endl << "Copy" << endl;
	Copy(bt, bt2);
	cout << "PreOrderTraverse" << endl;
	PreOrderTraverse(bt2);

	cout << endl << endl << "Depth = " << Depth(bt) << endl << endl;
	
	cout << "NodeCount = " << NodeCount(bt) << endl << endl;

	cout << "LeaveCount = " << LeaveCount(bt) << endl << endl;

	return 0;
}
