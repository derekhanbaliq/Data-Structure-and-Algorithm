#include <iostream>
#include <stdlib.h> //malloc & free

using namespace std;

//general define 在01文件中已经定义可以不用写 
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

#define FILL_SIZE		10

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

//填充链表L - 自定义函数
void FillList(LinkList& L)
{
	Lnode* p;

	p = L; //保存链表L的头指针

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			L->data = NULL; //头指针数据域为空
		}
		else if (i == 1)
		{
			L->data = 971105; //头结点数据域为info
		}
		else
		{
			L->data = i; //whatever
		}
		
		L->next = new Lnode;

		L = L->next; //移位
	}

	L->next = NULL; //对于链表L最后一个节点的next 要手动赋值NULL 否则它会乱指!
	
	L = p;
}

//打印链表L - 自定义函数
void PrintList(LinkList L) //不改变实参 所以不用引用
{
	while (L->next != NULL)
	{
		cout << L->data << "\t";
		cout << L->next << endl;

		L = L->next; //移位
	}

	cout << endl;
}

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

//销毁单链表L
Status DestroyList(LinkList L)
{
	Lnode* p; //定义一个节点类型的指针变量
	while (L->next) //while(L!=NULL)
	{
		p = L;
		L = L->next;
		delete p;
	}

	return OK;
}

int main(void)
{
	LinkList list;
	int s;

	s = InitList(list);
	cout << "init list = " << s << endl << endl;

	s = IsEmpty(list);
	cout << "is empty = " << s << endl << endl;

	FillList(list);
	PrintList(list);

	s = DestroyList(list);
	cout << "destroy list = " << s << endl << endl;

	return 0;
}
