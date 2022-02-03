#include <iostream>
#include <stdlib.h> //malloc & free

using namespace std;

//general define 在01文件中已经定义可以不用写 
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

//typedef 仍需声明
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;		//数据域
	struct Lnode* next; //指针域 - 自己定义自己 嵌套定义
} Lnode, * LinkList;	//两个都是数据类型！ 给Lnode重新起名为Lnode LinkList为指向结构体Lnode的指针类型
//定义链表L：LinkList L;
//定义节点指针p：Lnode *p = LinkList p 但常用后者表明链表 前者表明节点指针

//初始化链表L
Status InitList(LinkList& L)
{
	//1 生成新结点作头结点，用头指针L指向头结点
	L = new Lnode;
	//L = (LinkList)malloc(sizeof(Lnode));

	//2 将头结点的指针域置空
	L->next = NULL;

	return OK;
}

//判断链表L是否为空
Status IsEmpty(LinkList L)
{
	if (L->next)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main(void)
{
	LinkList list;
	int s;

	s = InitList(list);
	cout << "init status = " << s << endl;

	s = IsEmpty(list);
	cout << "is empty = " << s << endl;


	return 0;
}
