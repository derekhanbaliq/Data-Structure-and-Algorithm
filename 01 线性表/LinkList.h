#pragma once
#include <iostream>

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

//填充链表L - 自定义算法1
void FillList(LinkList& L);

//打印链表L - 自定义算法2
void PrintList(LinkList L);

//初始化链表L
Status InitList(LinkList& L);

//判断链表L是否为空 - 补充算法1
Status IsEmpty(LinkList L);

//销毁单链表L - 补充算法2
Status DestroyList(LinkList L);

//清空单链表L - 补充算法3
Status ClearList(LinkList& L);

//求单链表L表长 - 补充算法4
int ListLength(LinkList L);

//取单链表L中第i个元素的内容
Status GetElem(LinkList L, int i, ElemType& e);

//在单链表中查找值为e的数据元素
//找到返回L中值为e的数据元素地址 失败返回NULL
Lnode* LocateElemAddress(LinkList L, ElemType e);

//在单链表中查找值为e的数据元素的位置序号
//找到返回L中值为e的数据元素序号 失败返回NULL
int LocateElemIndex(LinkList L, ElemType e);

//在单链表L中第i个元素之前插入数据元素e
Status ListInsert(LinkList& L, int i, ElemType e);

//将单链表L中第i个元素删除
Status ListDelete(LinkList& L, int i, ElemType& e);

//头插法建立单链表L
void CreateHeadList(LinkList& L, int n);

//尾插法建立单链表L
void CreateTailList(LinkList& L, int n);