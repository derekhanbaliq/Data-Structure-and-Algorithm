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
typedef int KeyType;

//数据元素类型定义
typedef struct
{
	KeyType key; //关键字域
	//其他域
} ElemType;

//顺序表结构类型定义
typedef struct
{
	ElemType* R; //表基地址
	int length; //表长
}SSTable; //Sequential Search Table

SSTable ST; //定义顺序表ST

int main(void)
{


	return 0;
}
