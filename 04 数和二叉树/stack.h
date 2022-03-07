#pragma once
#include <iostream>

using namespace std;

typedef int Status;

typedef int TElemType;
typedef struct BiNode //二叉链表
{
	TElemType data;
	struct BiNode* lchild, * rchild; //左右孩子指针
}BiNode, * BiTree;

typedef BiNode* SElemType;

typedef struct
{
	SElemType* base;	//栈底指针
	SElemType* top;		//栈顶指针
	int stacksize;		//栈可用最大容量
}SqStack;

//顺序栈S的初始化
Status InitStack(SqStack& S);

//判断顺序栈S是否为空
Status IsStackEmpty(SqStack S);

//打印顺序栈S - 自定义函数1
void PrintStack(SqStack S);

//填充顺序栈S - 自定义函数2
Status FillStack(SqStack& S);

//求顺序栈S长度
int StackLength(SqStack S);

//清空顺序栈S
Status ClearStack(SqStack S);

//销毁顺序栈S
Status DestroyStack(SqStack& S);

//顺序栈S的入栈
Status Push(SqStack& S, SElemType e);

//顺序栈S的出栈
Status Pop(SqStack& S, SElemType& e);
