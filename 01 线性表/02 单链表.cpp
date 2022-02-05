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

//填充链表L - 自定义函数1
void FillList(LinkList& L)
{
	Lnode* p;

	p = L; //保存链表L的头指针

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			L->data = 971105; //头结点数据域为info
		}
		else
		{
			L->data = 100 - 10 * i; //whatever
		}
		
		L->next = new Lnode;

		L = L->next; //移位
	}

	L->next = NULL; //对于链表L最后一个节点的next 要手动赋值NULL 否则它会乱指!
	
	L = p;
}

//打印链表L - 自定义函数2
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

//判断链表L是否为空 - 补充算法1
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

//销毁单链表L - 补充算法2
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

//清空单链表L - 补充算法3
Status ClearList(LinkList& L)
{
	Lnode* p, * q; //构建两个节点类型的指针变量

	p = L->next; //p指向头结点指针域

	while (p) //while (p != NULL) 没到表尾
	{
		q = p->next; //q指向下一个节点
		delete p;
		p = q;
	}
	//已出循环 p q 均为空

	L->next = NULL; //头指针置空

	return OK;
}

//求单链表L表长 - 补充算法4
int ListLength(LinkList L)
{
	int i = 0;
	Lnode* p;

	p = L->next; //p指向第一个节点
	while (p) //p != NULL
	{
		i++;
		p = p->next;
	}

	return i;
}

//取单链表L中第i个元素的内容
Status GetElem(LinkList L, int i, ElemType& e)
{
	Lnode* p = L->next; //指针指向首元结点
	int j = 1;

	while (p && j < i) //p不为空还未到第i个元素
	{
		p = p->next;
		j++; //++j; //i = 1; j = ++i; (i=2 j=2)
	}

	if (!p || j > i) //i <= 0 or j > length or p == NULL
	{
		return ERROR;
	}

	e = p->data;

	return OK;
}

//在单链表中查找值为e的数据元素
//找到返回L中值为e的数据元素地址 失败返回NULL
Lnode* LocateElemAddress(LinkList L, ElemType e)
{
	Lnode* p = L->next; //指针指向首元结点

	while (p && p->data != e) //p != NULL 且 p的数据域不是e
	{
		p = p->next;
	}

	//如果还未找到 p此时就已经是NULL了
	return p; //返回指针变量p
}

//在单链表中查找值为e的数据元素的位置序号
//找到返回L中值为e的数据元素序号 失败返回NULL
int LocateElemIndex(LinkList L, ElemType e)
{
	Lnode* p = L->next; //指针指向首元结点
	int j = 1;

	while (p && p->data != e)
	{
		p = p->next;
		j++;
	}

	if (p)
	{
		return j;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	LinkList list;
	int s, len, i;
	ElemType e;
	Lnode* ptr;

	//初始化
	s = InitList(list);
	cout << "init list = " << s << endl << endl;
	
	//判断是否为空
	s = IsEmpty(list);
	cout << "is empty = " << s << endl << endl;

	//填充并打印
	FillList(list);
	PrintList(list);

	//查看长度
	len = ListLength(list);
	cout << "len = " << len << endl << endl;

	//获取第n个元素
	s = GetElem(list, 4, e);
	cout << "s = " << s << endl;
	cout << "e = " << e << endl << endl;

	//查找元素
	ptr = LocateElemAddress(list, -40);
	cout << "ptr = " << ptr << endl << endl; //返回地址
	i = LocateElemIndex(list, 60);
	cout << "i = " << i << endl << endl; //返回index

	//清空并打印
	s = ClearList(list);
	cout << "clear list = " << s << endl;
	PrintList(list);
	cout << "over" << endl << endl;
	
	//销毁
	s = DestroyList(list);
	cout << "destroy list = " << s << endl << endl;

	return 0;
}
