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
typedef int KeyType;

//数据元素类型定义
typedef struct
{
	KeyType key; //关键字域
	//其他域...
} ElemType;

//顺序表结构类型定义
typedef struct
{
	ElemType* R; //表基地址
	int length; //表长
}SSTable; //Sequential Search Table

SSTable ST; //定义顺序表ST

int Search_Bin(SSTable ST, KeyType key)
{
	int low = 1;
	int high = ST.length; //设置区间初值

	while (low <= high)
	{
		int mid = (low + high) / 2;
		
		if (ST.R[mid].key == key)
		{
			return mid; //找到待查元素
		}
		else if (key < ST.R[mid].key) //缩小查找区间
		{
			high = mid - 1; //继续在前半区间进行查找
		}
		else
		{
			low = mid + 1; //继续在前半区间进行查找
		}
	}

	return 0; //顺序表中不存在待查元素
}

//递归式折半查找
int Search_Bin_Recursion(SSTable ST, KeyType key, int low, int high)
{
	if (low > high)
	{
		return 0; //查找不到时返回0
	}

	int mid = (low + high) / 2;

	if (key == ST.R[mid].key)
	{
		return mid;
	}
	else if (key < ST.R[mid].key)
	{
		Search_Bin_Recursion(ST, key, low, mid - 1); //递归 在前半区间进行查找
	}
	else
	{
		Search_Bin_Recursion(ST, key, mid + 1, high); //递归 在后半区间进行查找
	}
}

int main02(void)
{


	return 0;
}
