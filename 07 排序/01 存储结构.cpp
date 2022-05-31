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

//冒泡排序
void BubbleSort(SqList& L)
{
	int m, n, j;
	RedType x; //交换时临时存储

	for (m = 1; m <= n - 1; m++)
	{
		for (j = 1; j <= n - m; j++)
		{
			if (L.r[j].key > L.r[j + 1].key)
			{
				x = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = x;
			}
		}
	}
}
//改进版冒泡排序
void BubbleSort(SqList& L)
{
	int m, n, j;
	int flag = 1;
	RedType x; //交换时临时存储

	for (m = 1; m <= n - 1 && flag == 1; m++)
	{
		flag = 0;
		
		for (j = 1; j <= n - m; j++)
		{
			if (L.r[j].key > L.r[j + 1].key)
			{
				flag = 1; //发生交换 flag置1 若本趟没发生交换 flag保持为0
				
				x = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = x;
			}
		}
	}
}

//对顺序表L快速排序
void QSort(SqList& L, int low, int high)
{
	if (low < high) //长度大于1
	{
		int pivotloc = Partition(L, low, high); //将L.r[low...high]一分为二，pivotloc为枢轴元素排好序的位置
		QSort(L, low, pivotloc - 1); //对低子表递归排序
		QSort(L, pivotloc + 1, high); //对高子表递归排序
	}
}
int Partition(SqList& L, int low, int high)
{
	int pivotkey = L.r[low].key;
	
	L.r[0] = L.r[low];
	
	while (low < high)
	{
		while (low < high && L.r[high].key >= pivotkey)
		{
			--high;
		}
		L.r[low] = L.r[high];

		while (low < high && L.r[low].key <= pivotkey)
		{
			++low;
		}
		L.r[high] = L.r[low];
	}

	L.r[low] = L.r[0];

	return low;
}

//简单选择排序
void SelectSort(SqList& L)
{
	int i, k, j;
	RedType box;
	
	for (i; i < L.length; ++i)
	{
		k = i;

		for (j = i + 1; j <= L.length; j++)
		{
			if (L.r[j].key < L.r[k].key)
			{
				k = j; //记录最小值位置
			}
		}

		if (k != i) //交换
		{
			box = L.r[k];
			L.r[k] = L.r[i];
			L.r[i] = box;
		}
	}
}

//堆排序
void HeapAdjust(KeyType R[], int s, int m)
//已知R[s...m]中记录的关键字除R[s]之外均满足堆的定义 本函数调整R[s]的关键字 使R[s...m]成为一个大根堆
{
	KeyType rc = R[s];

	for (int j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && R[j] < R[j + 1]) //沿着key较大的孩子结点向下筛选
		{
			++j; //j为key较大的记录的下标
		}
		if (rc >= R[j])
		{
			break;
		}
		R[s] = R[j];
		s = j; //rc应插入在位置s上
	}

	R[s] = rc; //插入
}
//对R[1]到R[n]进行堆排序
void HeapSort(KeyType R[])
{
	int i;
	int n = sizeof(R) / sizeof(R[0]);

	for (i = n / 2; i >= 1; i--)
	{
		HeapAdjust(R, i, n); //建初始堆
	}
	for (i = n; i > 1; i--)
	{
		swap(R[1], R[i]); //根与最后一个元素交换
		HeapAdjust(R, 1, i - 1); //对R[1]到R[i-1]重新建堆
	}
}

int main(void)
{
	//SqList L;
	//QSort(L, 1, L.length);

	return 0;
}
