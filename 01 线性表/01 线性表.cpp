#include <iostream>
#include <stdlib.h> //malloc & free

using namespace std;

//general define
#define TRUE		1
#define FALSE		0

#define OK			1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

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
	ElemType *elem;
	int length;
} SqList; //动态数组的方式 定义顺序表的数据类型

//打印线性表L
void PrintList(SqList L)
{
	cout << "print sequence list: " << endl;
	
	//打印索引号
	cout << "index:    "; 
	for (int i = 0; i < L.length; i++)
	{
		cout << i + 1 << "\t"; //索引号从1开始
	}
	cout << endl;
	
	cout << "elements: ";
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << "\t";
	}
	cout << endl;
	cout << "length: " << L.length << endl << endl;
}

//填充线性表L - 1, 2, 3... , 20
void FillList(SqList& L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L.elem[i] = pow(i, 2) - 4 * i + 4; //anyway
	}
	L.length = MAXSIZE;
}

//初始化线性表L
Status InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE]; //C++ new 动态分配
	//L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); //C语言malloc动态内存分配 - heap

	if (!L.elem) //L.elem == 0
	{
		exit(OVERFLOW); //内存不够 没有分配到地址 存储分配失败 里面存空值 溢出错误
	}

	L.length = 0; //空表长度为0

	return OK;
}

//销毁线性表L
void DestoryList(SqList& L)
{
	if (L.elem) //如果这块空间存储了东西 L存在
	{
		delete L.elem; //释放存储空间
	}
}

//清空线性表L
void ClearList(SqList& L)
{
	L.length = 0; //长度置0
}

//求线性表L的长度
int GetLength(SqList L)
{
	return (L.length);
}

//判断线性表L是否为空
int IsEmpty(SqList L)
{
	if (L.length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//根据位置i获取相应位置数据元素的内容 - O(1) 随机存取 链式存储做不到
int GetElem(SqList L, int i, ElemType& e)
{
	if (i<1 || i>L.length) //从1索引
	{
		return ERROR;
	}

	e = L.elem[i - 1]; //第i-1个单元存储着第i个数据

	return OK;
}


int main(void)
{
	SqList list;
	int box; //just a test space

	InitList(list);
	PrintList(list);

	FillList(list);
	PrintList(list);
	cout << "GetLength(list) = " << GetLength(list) << endl << endl;
	GetElem(list, 6, box);
	cout << "box = " << box << endl << endl;

	ClearList(list);
	PrintList(list);
	cout << "IsEmpty(list) = " << IsEmpty(list) << endl << endl;

	DestoryList(list);

	return 0;
}
