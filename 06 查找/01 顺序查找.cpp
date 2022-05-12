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

//����Ԫ�����Ͷ���
typedef struct
{
	KeyType key; //�ؼ�����
	//������...
} ElemType;

//˳���ṹ���Ͷ���
typedef struct
{
	ElemType* R; //�����ַ
	int length; //��
}SSTable; //Sequential Search Table

SSTable ST; //����˳���ST

int Search_Seq(SSTable ST, KeyType key)
{
	for (int i = ST.length; i >= 1; --i)
	{
		if (ST.R[i].key == key)
		{
			return i;
		}
	}

	return 0;
}

int Search_Seq_1(SSTable ST, KeyType key)
{
	int i;
	
	for (i = ST.length; ST.R[i].key != key; --i)
	{
		if (i <= 0)
		{
			break;
		}
	}

	if (i > 0)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

int Search_Seq_2(SSTable ST, KeyType key)
{
	int i;

	for (i = ST.length; ST.R[i].key != key && i > 0; --i);

	if (i > 0)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

//���Ӽ����ڵ�˳�����
int Search_Seq_New(SSTable ST, KeyType key)
{
	int i;
	
	ST.R[0].key = key;

	for (i = ST.length; ST.R[i].key != key && i > 0; --i);
		return i;
}

int main01(void)
{


	return 0;
}
