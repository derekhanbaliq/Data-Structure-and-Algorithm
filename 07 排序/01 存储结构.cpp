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

//ð������
void BubbleSort(SqList& L)
{
	int m, n, j;
	RedType x; //����ʱ��ʱ�洢

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
//�Ľ���ð������
void BubbleSort(SqList& L)
{
	int m, n, j;
	int flag = 1;
	RedType x; //����ʱ��ʱ�洢

	for (m = 1; m <= n - 1 && flag == 1; m++)
	{
		flag = 0;
		
		for (j = 1; j <= n - m; j++)
		{
			if (L.r[j].key > L.r[j + 1].key)
			{
				flag = 1; //�������� flag��1 ������û�������� flag����Ϊ0
				
				x = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = x;
			}
		}
	}
}

//��˳���L��������
void QSort(SqList& L, int low, int high)
{
	if (low < high) //���ȴ���1
	{
		int pivotloc = Partition(L, low, high); //��L.r[low...high]һ��Ϊ����pivotlocΪ����Ԫ���ź����λ��
		QSort(L, low, pivotloc - 1); //�Ե��ӱ�ݹ�����
		QSort(L, pivotloc + 1, high); //�Ը��ӱ�ݹ�����
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

//��ѡ������
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
				k = j; //��¼��Сֵλ��
			}
		}

		if (k != i) //����
		{
			box = L.r[k];
			L.r[k] = L.r[i];
			L.r[i] = box;
		}
	}
}

//������
void HeapAdjust(KeyType R[], int s, int m)
//��֪R[s...m]�м�¼�Ĺؼ��ֳ�R[s]֮�������ѵĶ��� ����������R[s]�Ĺؼ��� ʹR[s...m]��Ϊһ�������
{
	KeyType rc = R[s];

	for (int j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && R[j] < R[j + 1]) //����key�ϴ�ĺ��ӽ������ɸѡ
		{
			++j; //jΪkey�ϴ�ļ�¼���±�
		}
		if (rc >= R[j])
		{
			break;
		}
		R[s] = R[j];
		s = j; //rcӦ������λ��s��
	}

	R[s] = rc; //����
}
//��R[1]��R[n]���ж�����
void HeapSort(KeyType R[])
{
	int i;
	int n = sizeof(R) / sizeof(R[0]);

	for (i = n / 2; i >= 1; i--)
	{
		HeapAdjust(R, i, n); //����ʼ��
	}
	for (i = n; i > 1; i--)
	{
		swap(R[1], R[i]); //�������һ��Ԫ�ؽ���
		HeapAdjust(R, 1, i - 1); //��R[1]��R[i-1]���½���
	}
}

int main(void)
{
	//SqList L;
	//QSort(L, 1, L.length);

	return 0;
}
