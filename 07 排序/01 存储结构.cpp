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

typedef struct //����ÿ����¼(����Ԫ��)�Ľṹ
{
	KeyType key; //�ؼ���
	InfoType otherinfo; //����������
}RedType; //Record Type

typedef struct //����˳���Ľṹ
{
	RedType r[MAXSIZE + 1]; //�洢˳�������� r[0]һ�����ڱ��򻺳���
	int length; //˳���ĳ���
}SqList;

//ֱ�Ӳ�������
void InsertSort(SqList& L)
{
	int i, j;

	for (i = 2; i <= L.length; ++i)
	{
		if (L.r[i].key < L.r[i - 1].key) //��< �轫L.r[i]���������ӱ�
		{
			L.r[0] = L.r[i]; //����Ϊ�ڱ�
			for (j = i - 1; L.r[0].key < L.r[j].key; --j)
			{
				L.r[j + 1] = L.r[j]; //��¼����
			}
			L.r[j + 1] = L.r[0]; //���뵽��ȷλ��
		}
	}
}

//�۰��������
void BInsertSort(SqList& L)
{
	int i, j, low, high, mid;

	for (i = 2; i <= L.length; ++i)
	{
		L.r[0] = L.r[i]; //��ǰ����Ԫ�ش浽"�ڱ�"λ��
		low = 1;
		high = i - 1; //���ö��ֲ��ҷ����Ҳ���λ��
		
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
		} //ѭ������ high + 1 Ϊ����λ��

		for (j = i - 1; j >= high + 1; --j)
		{
			L.r[j + 1] = L.r[j]; //�ƶ�Ԫ��
		}
		L.r[high + 1] = L.r[0]; //���뵽��ȷλ��
	}
}

//ϣ�������㷨(������)
void ShellSort(SqList& L, int dlta[], int t)
{
	//����������dlta[0...t-1]��˳���L��ϣ������
	for (int k = 0; k < t; ++k)
	{
		ShellInsert(L, dlta[k]); //һ������Ϊdlta[k]�Ĳ�������
	}
}

//��˳���L����һ������Ϊdk��Shell���� dkΪ��������
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
