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

#define MAXSIZE 20

typedef int KeyType;
typedef int InfoType;

typedef struct //定义每个记录(数据元素)的结构
{
	KeyType key; //关键字
	InfoType otherinfo; //其他数据项
}RedType; //Record Type

typedef struct //定义顺序表的结构
{
	RedType r[MAXSIZE + 1]; //存储顺序表的向量 r[0]一般做哨兵或缓冲区
	int length; //顺序表的长度
}SqList;

//直接插入排序
void InsertSort(SqList& L)
{
	int i, j;

	for (i = 2; i <= L.length; ++i)
	{
		if (L.r[i].key < L.r[i - 1].key) //若< 需将L.r[i]插入有序子表
		{
			L.r[0] = L.r[i]; //复制为哨兵
			for (j = i - 1; L.r[0].key < L.r[j].key; --j)
			{
				L.r[j + 1] = L.r[j]; //记录后移
			}
			L.r[j + 1] = L.r[0]; //插入到正确位置
		}
	}
}

//折半插入排序
void BInsertSort(SqList& L)
{
	int i, j, low, high, mid;

	for (i = 2; i <= L.length; ++i)
	{
		L.r[0] = L.r[i]; //当前插入元素存到"哨兵"位置
		low = 1;
		high = i - 1; //采用二分查找法查找插入位置
		
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		} //循环结束 high + 1 为插入位置

		for (j = i - 1; j >= high + 1; --j)
		{
			L.r[j + 1] = L.r[j]; //移动元素
		}
		L.r[high + 1] = L.r[0]; //插入到正确位置
	}
}

//希尔排序算法(主程序)
void ShellSort(SqList& L, int dlta[], int t)
{
	//按增量序列dlta[0...t-1]对顺序表L作希尔排序
	for (int k = 0; k < t; ++k)
	{
		ShellInsert(L, dlta[k]); //一趟增量为dlta[k]的插入排序
	}
}

//对顺序表L进行一趟增量为dk的Shell排序 dk为步长因子
void ShellInsert(SqList& L, int dk)
{
	int i, j;
	
	for (i = dk + 1; i <= L.length; ++i)
	{
		if (L.r[i].key < L.r[i - dk].key)
		{
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && (L.r[0].key < L.r[j].key); j = j - dk)
			{
				L.r[j + dk] = L.r[j];
			}
			L.r[j + dk] = L.r[0];
		}
	}
}

int main(void)
{

	return 0;
}
