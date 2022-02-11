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

//打印链表L - 自定义算法1 - 在02中已定义
void PrintCircularList(LinkList l) //不改变实参 所以不用引用
{
	while (l->next != NULL)
	{
		cout << l->data << "\t";
		cout << l->next << endl;

		l = l->next; //移位
	}

	cout << endl;
}

//头插法建立循环链表 - 自定义算法2
void CreateCircularHeadList(LinkList& L, int n)
{
	L = new Lnode;
	Lnode* q;

	L->data = 100;
	L->next = NULL;

	for (int i = n; i > 0; --i)
	{
		Lnode* p = new Lnode; //生成新结点 p=(Lnode*)malloc(sizeof(Lnode));
		p->data = i * 10; //输入元素值 cin >> p->data; //scanf(&p->data); whatever

		p->next = L->next; //插入到表头
		L->next = p;
	}

	q = L->next;

	for (int i = 0; i < n - 1; i++) //找到尾结点
	{
		q = q->next;
	}

	q->next = L; //尾结点 指向自己的头结点循环起来
}

//尾插法建立循环链表 - 自定义算法3
void CreateCircularTailList(LinkList& L, int n)
{
	L = new Lnode;
	Lnode* r; //尾指针 一个标记

	L->data = 888;
	L->next = NULL;

	r = L; //尾指针r指向头结点

	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		p->data = i; //cin >> p->data;

		p->next = NULL;
		r->next = p; //插入到表尾
		r = p; //指向新的尾结点
	}

	r->next = L; //循环构建
}

//带尾指针循环链表的合并
LinkList ConnectCircularList(LinkList Ta, LinkList Tb) //假设Ta和Tb都是非空的单循环链表
{
	Lnode* p = Ta->next; //1 p存表头结点

	Ta->next = Tb->next->next; //2 Tb表头连接Ta表尾

	delete Tb->next; //3 释放Tb表头结点

	Tb->next = p; //4 修改指针

	return Tb;
}

int main03(void)
{
	LinkList Ta, Tb, Tc;

	cout << "\t\t\t\t\t\t!!!!Warning!!!!\t\t\t\t\t\t" << endl << endl;


	//头插法创建循环链表Ta
	CreateCircularHeadList(Ta, 4);
	//PrintCircularList(Ta); //死循环打印
	//s = DestroyList(Ta); //循环链表删除会崩

	//尾插法创建循环链表Tb
	CreateCircularTailList(Tb, 8);
	//PrintCircularList(Tb); //死循环打印

	//循环链表的合并成Tc
	Tc = ConnectCircularList(Ta, Tb);
	PrintCircularList(Tc); //死循环打印

	return 0;
}
