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
//定义结点指针p：Lnode *p = LinkList p 但常用后者表明链表 前者表明结点指针

/*
 * 1）每个链表结点，可能会发生删除插入操作，所以注定了结点结构体中的指针肯定会不断的发生变化———链表结点的定义一定要用指针来对结点进行间接访问
 * 2）在传入头结点指针给调用函数时，在函数的操作过程中，会给头结点分配内存空间，对其进行修改。所以我们要用指向头结点指针的指针来作为函数的参数。 - 在我们的函数中，用 引用 作 需要修改的参数
 * ————————————————
 * 原文链接：https ://blog.csdn.net/ivebeenready/article/details/50551853
*/

//填充链表L - 自定义算法1
void FillList(LinkList& L)
{
	Lnode* p; //栈区开辟
	//Lnode* p = new Lnode; 要是用堆区 就手动开辟手动释放即可 - 后边要delete

	p = L; //获取链表L的头指针

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			p->data = 971105; //头结点数据域为info
		}
		else
		{
			p->data = 100 - 10 * i; //whatever
		}
		
		p->next = new Lnode;

		p = p->next; //移位
	}

	p->next = NULL; //对于链表L最后一个结点的next 要手动赋值NULL 否则它会乱指!
}

//打印链表L - 自定义算法2
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
Status DestroyList(LinkList& L)
{
	Lnode* p; //定义一个结点类型的指针变量
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
	Lnode* p, * q; //构建两个结点类型的指针变量

	p = L->next; //p指向头结点指针域

	while (p) //while (p != NULL) 没到表尾
	{
		q = p->next; //q指向下一个结点
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

	p = L->next; //p指向第一个结点
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

//在单链表L中第i个元素之前插入数据元素e
Status ListInsert(LinkList& L, int i, ElemType e)
{
	Lnode* p = L;
	int j = 0;

	while (p && j < i - 1) //寻找第i-1个结点 p指向i-1结点
	{
		p = p->next;
		j++; //++j
	}

	if (!p || j > i - 1) //p==NULL(j>表长+1) or j<1 即结点不存在
	{
		return ERROR;
	}

	Lnode* s = new Lnode; //生成新结点
	s->data = e;
	s->next = p->next; //后边的链接
	p->next = s; //前边的链接 s是地址！

	return OK;
}

//将单链表L中第i个元素删除
Status ListDelete(LinkList& L, int i, ElemType& e)
{
	Lnode* p = L; //从头结点开始数
	Lnode* q;
	int j = 0;

	while (p->next && j < i - 1) //寻找第i个结点 并令p指向其前驱
	{
		p = p->next;
		j++;
	}

	if (!(p->next) || j > i - 1) //小于0 大于n
	{
		return ERROR;
	}

	q = p->next; //临时保存被删结点的地址以备释放
	p->next = q->next; //p->next->next
	e = q->data;

	delete q; //释放删除结点的空间

	return OK;
}

//头插法建立单链表L
void CreateHeadList(LinkList& L, int n)
{
	L = new Lnode;

	L->next = NULL; //先建立一个带头结点的单链表

	for (int i = n; i > 0; --i)
	{
		Lnode* p = new Lnode; //生成新结点 p=(Lnode*)malloc(sizeof(Lnode));
		p->data = i; //输入元素值 cin >> p->data; //scanf(&p->data); whatever
		
		p->next = L->next; //插入到表头
		L->next = p;
	}
}

//尾插法建立单链表L
void CreateTailList(LinkList& L, int n)
{
	L = new Lnode;
	Lnode* r; //尾指针 一个标记

	L->next = NULL;

	r = L; //尾指针r指向头结点

	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		p->data = i + 1; //cin >> p->data;

		p->next = NULL;
		r->next = p; //插入到表尾
		r = p; //指向新的尾结点
	}
}

int main(void)
{
	LinkList list, headList, tailList;
	int s, len, i;
	ElemType e;
	Lnode* ptr;
	LinkList Ta, Tb, Tc;

	cout << "LinkList test" << endl << endl;

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
	cout << "list len = " << len << endl << endl;

	//获取第n个元素
	s = GetElem(list, 4, e);
	cout << "get elem = " << s << endl;
	cout << "e = " << e << endl << endl;

	//查找元素
	ptr = LocateElemAddress(list, -40);
	cout << "locate elem address ptr = " << ptr << endl << endl; //返回地址
	i = LocateElemIndex(list, 60);
	cout << "locate elem index i = " << i << endl << endl; //返回index

	//插入
	s = ListInsert(list, 8, 666);
	cout << "list insert = " << s << endl;
	PrintList(list);

	//删除
	s = ListDelete(list, 8, e);
	cout << "list insert = " << s << endl;
	PrintList(list);

	//清空并打印
	s = ClearList(list);
	cout << "clear list = " << s << endl;
	PrintList(list);
	cout << "over" << endl << endl;
	
	//销毁
	s = DestroyList(list);
	cout << "destroy list = " << s << endl << endl;

	//头插法建立单链表
	CreateHeadList(headList, 5); 
	PrintList(headList);
	s = DestroyList(headList);
	//cout << "destroy list = " << s << endl << endl;

	//尾插法建立单链表
	CreateTailList(tailList, 10);
	PrintList(tailList);
	s = DestroyList(tailList);
	//cout << "destroy list = " << s << endl << endl;

	//创建列表和结点通常用 Lnode * 或 LinkList 否则用Lnode别人指你得取地址& 很麻烦
	//Lnode* test1;
	//test1->data = 1;
	//test1->next = list;
	//Lnode test2;
	//test2.data = 1;
	//test2.next = list;

	return 0;
}
