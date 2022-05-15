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

int Search_Bin(SSTable ST, KeyType key)
{
	int low = 1;
	int high = ST.length; //���������ֵ

	while (low <= high)
	{
		int mid = (low + high) / 2;
		
		if (ST.R[mid].key == key)
		{
			return mid; //�ҵ�����Ԫ��
		}
		else if (key < ST.R[mid].key) //��С��������
		{
			high = mid - 1; //������ǰ��������в���
		}
		else
		{
			low = mid + 1; //������ǰ��������в���
		}
	}

	return 0; //˳����в����ڴ���Ԫ��
}

//�ݹ�ʽ�۰����
int Search_Bin_Recursion(SSTable ST, KeyType key, int low, int high)
{
	if (low > high)
	{
		return 0; //���Ҳ���ʱ����0
	}

	int mid = (low + high) / 2;

	if (key == ST.R[mid].key)
	{
		return mid;
	}
	else if (key < ST.R[mid].key)
	{
		Search_Bin_Recursion(ST, key, low, mid - 1); //�ݹ� ��ǰ��������в���
	}
	else
	{
		Search_Bin_Recursion(ST, key, mid + 1, high); //�ݹ� �ں��������в���
	}
}

int main02(void)
{


	return 0;
}
