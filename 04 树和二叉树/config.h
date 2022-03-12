#pragma once
#include <iostream>

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

#define MAXSSIZE 10
#define MAXQSIZE 8

#define MAX_TREE_SIZE	20

typedef int Status;

//二叉树typedef
typedef char TElemType;
typedef struct BiNode //二叉链表
{
	TElemType data;
	struct BiNode* lchild, * rchild; //左右孩子指针
}BiNode, * BiTree;

//二叉树栈typedef
typedef BiNode* SElemType;
typedef struct
{
	SElemType* base;	//栈底指针
	SElemType* top;		//栈顶指针
	int stacksize;		//栈可用最大容量
}SqStack;

//二叉树队列typedef
typedef BiNode* QElemType;
typedef QElemType BTNode; //也可用这种方式定义
typedef struct
{
	QElemType* base;	//动态分配存储空间
	int front;			//头指针 - 若队列不空 指向队列头元素
	int rear;			//尾指针 表示队尾元素的下标 - 若队列不空 指向队列尾元素的下一个位置
}SqQueue;

//三叉链表typedef
typedef struct TriNode //三叉链表
{
	TElemType data;
	struct BiNode* lchild, * parent, * rchild;
}TriNode, * TriTree;

//线索二叉树typedef
typedef struct BiThrNode
{
	int data;
	int ltag, rtag;
	struct BiThrNode* lchild, * rchild;
}BiThrNode, * BiThrTree;

//树的存储结构

//双亲表示法
typedef struct PTNode
{
	TElemType data;
	int parent; //双亲位置域
}PTNode;
typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int r, n; //根结点的位置和结点个数
}PTree;

//孩子链表
typedef struct CTNode //孩子结点结构
{
	int child;
	struct CTNode* next;
}*ChildPtr;
typedef struct //双亲结点结构
{
	TElemType data;
	ChildPtr firstchild; //孩子链表头指针
}CTBox;
typedef struct //树结构
{
	CTBox nodes[MAX_TREE_SIZE];
	int n, r; //结点数和根结点的位置
}CTree;

