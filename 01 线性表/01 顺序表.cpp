#include <iostream>
#include <stdlib.h> //malloc & free

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
	ElemType *elem; //指针 指向一个数组
	int length;
} SqList; //动态数组的方式 定义顺序表的数据类型

//打印顺序表L
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

//填充顺序表L - Whatever
void FillList(SqList& L)
{
	for (int i = 0; i < MAXSIZE - 2; i++)
	{
		L.elem[i] = ElemType(ElemType(pow(i, 2)) - 4 * i + 4); //anyway
	}
	L.length = MAXSIZE - 2;
}

//初始化顺序表L
Status InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE]; //C++ new 动态分配
	//L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); //C语言malloc动态内存分配 - heap

	if (!L.elem) //L.elem == 0
	{
		exit(STACK_OVERFLOW); //内存不够 没有分配到地址 存储分配失败 里面存空值 溢出错误
	}

	L.length = 0; //空表长度为0

	return OK;
}

//销毁顺序表L
void DestoryList(SqList& L)
{
	if (L.elem) //如果这块空间存储了东西 L存在
	{
		delete L.elem; //释放存储空间
	}
}

//清空顺序表L
void ClearList(SqList& L)
{
	L.length = 0; //长度置0
}

//求顺序表L的长度
int GetLength(SqList L)
{
	return (L.length);
}

//判断顺序表L是否为空
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

//在顺序表L中查找值为e的数据元素 返回其序号(第几个元素)
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			return i + 1;
		}
	}

	return 0; //查找失败
}

//在顺序表L的第i个位置插入元素e
Status ListInsert(SqList& L, int i, ElemType e)
{
	//1 判断插入位置i是否合法
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}

	//2 判断当前存储空间是否已满
	if (L.length == MAXSIZE)
	{
		return ERROR;
	}

	//3 将第i个位置的元素依次后移1位 空出地i个位置
	for (int j = L.length - 1; j >= i - 1; j--) //j是数组的index!
	{
		L.elem[j + 1] = L.elem[j];
	}

	//4 将新元素e放入第i个位置
	L.elem[i - 1] = e;

	//5 表长+1
	L.length++;

	return OK;
}

//在顺序表L的第i个位置删除元素e
Status ListDelete(SqList& L, int i, ElemType &e)
{
	//1 判断删除位置i是否合法
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}

	//将想要删除的元素保留在e中
	e = L.elem[i - 1];

	//3 将第i个位置的元素依次前移1位
	for (int j = i; j <= L.length - 1; j++) //j=i 因为要操作的元素 其数组下标是(i-1)+1
	{
		L.elem[j - 1] = L.elem[j];
	}

	//4 表长-1
	L.length--;

	return OK;
}

//change the main name to make sure there is only one main in the project
int main01(void)
{
	SqList list;
	int box; //just a test space
	Status s;

	InitList(list);
	PrintList(list);

	FillList(list);
	PrintList(list);
	
	//cout << "GetLength(list) = " << GetLength(list) << endl << endl;

	//GetElem(list, 6, box);
	//cout << "GetElem(list, 6, box), box = " << box << endl << endl;

	//cout << "LocateElem(list, 10) = " << LocateElem(list, 10) << endl << endl;

	s = ListInsert(list, 5, 999);
	//cout << "status is " << s << endl;
	PrintList(list);

	s = ListDelete(list, 8, box);
	//cout << "status is " << s << endl;
	cout << "ListDelete(list, 8, box), box = " << box << endl << endl;
	PrintList(list);

	//ClearList(list);
	//PrintList(list);
	//cout << "IsEmpty(list) = " << IsEmpty(list) << endl << endl;

	DestoryList(list);

	return 0;
}
