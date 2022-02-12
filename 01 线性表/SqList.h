#pragma once
#include <iostream>
using namespace std;

//general define
#define TRUE		1
#define FALSE		0
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

typedef int Status;
typedef int ElemType;

//sequence list setup
#define MAXSIZE 10

//typedef struct
//{
//	ElemType elem[MAXSIZE];
//	int length;
//} SqList; //静态数组的方式

typedef struct
{
	ElemType* elem;
	int length;
} SqList; //动态数组的方式 定义顺序表的数据类型

//打印顺序表L
void PrintList(SqList L);

//填充顺序表L - Whatever
void FillList(SqList& L);

//初始化顺序表L
Status InitList(SqList& L);

//销毁顺序表L
void DestoryList(SqList& L);

//清空顺序表L
void ClearList(SqList& L);

//求顺序表L的长度
int GetLength(SqList L);

//判断顺序表L是否为空
int IsEmpty(SqList L);

//根据位置i获取相应位置数据元素的内容 - O(1) 随机存取 链式存储做不到
int GetElem(SqList L, int i, ElemType& e);

//在顺序表L中查找值为e的数据元素 返回其序号(第几个元素)
int LocateElem(SqList L, ElemType e);

//在顺序表L的第i个位置插入元素e
Status ListInsert(SqList& L, int i, ElemType e);

//在顺序表L的第i个位置删除元素e
Status ListDelete(SqList& L, int i, ElemType& e);
