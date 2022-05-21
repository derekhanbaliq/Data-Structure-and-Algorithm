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

int main(void)
{

	return 0;
}
