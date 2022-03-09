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
//} SqList; //��̬����ķ�ʽ

typedef struct
{
	ElemType *elem; //ָ�� ָ��һ������
	int length;
} SqList; //��̬����ķ�ʽ ����˳������������

//��ӡ˳���L
void PrintList(SqList L)
{
	cout << "print sequence list: " << endl;
	
	//��ӡ������
	cout << "index:    "; 
	for (int i = 0; i < L.length; i++)
	{
		cout << i + 1 << "\t"; //�����Ŵ�1��ʼ
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

//���˳���L - Whatever
void FillList(SqList& L)
{
	for (int i = 0; i < MAXSIZE - 2; i++)
	{
		L.elem[i] = ElemType(ElemType(pow(i, 2)) - 4 * i + 4); //anyway
	}
	L.length = MAXSIZE - 2;
}

//��ʼ��˳���L
Status InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE]; //C++ new ��̬����
	//L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); //C����malloc��̬�ڴ���� - heap

	if (!L.elem) //L.elem == 0
	{
		exit(STACK_OVERFLOW); //�ڴ治�� û�з��䵽��ַ �洢����ʧ�� ������ֵ �������
	}

	L.length = 0; //�ձ���Ϊ0

	return OK;
}

//����˳���L
void DestoryList(SqList& L)
{
	if (L.elem) //������ռ�洢�˶��� L����
	{
		delete L.elem; //�ͷŴ洢�ռ�
	}
}

//���˳���L
void ClearList(SqList& L)
{
	L.length = 0; //������0
}

//��˳���L�ĳ���
int GetLength(SqList L)
{
	return (L.length);
}

//�ж�˳���L�Ƿ�Ϊ��
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

//����λ��i��ȡ��Ӧλ������Ԫ�ص����� - O(1) �����ȡ ��ʽ�洢������
int GetElem(SqList L, int i, ElemType& e)
{
	if (i<1 || i>L.length) //��1����
	{
		return ERROR;
	}

	e = L.elem[i - 1]; //��i-1����Ԫ�洢�ŵ�i������

	return OK;
}

//��˳���L�в���ֵΪe������Ԫ�� ���������(�ڼ���Ԫ��)
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			return i + 1;
		}
	}

	return 0; //����ʧ��
}

//��˳���L�ĵ�i��λ�ò���Ԫ��e
Status ListInsert(SqList& L, int i, ElemType e)
{
	//1 �жϲ���λ��i�Ƿ�Ϸ�
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}

	//2 �жϵ�ǰ�洢�ռ��Ƿ�����
	if (L.length == MAXSIZE)
	{
		return ERROR;
	}

	//3 ����i��λ�õ�Ԫ�����κ���1λ �ճ���i��λ��
	for (int j = L.length - 1; j >= i - 1; j--) //j�������index!
	{
		L.elem[j + 1] = L.elem[j];
	}

	//4 ����Ԫ��e�����i��λ��
	L.elem[i - 1] = e;

	//5 ��+1
	L.length++;

	return OK;
}

//��˳���L�ĵ�i��λ��ɾ��Ԫ��e
Status ListDelete(SqList& L, int i, ElemType &e)
{
	//1 �ж�ɾ��λ��i�Ƿ�Ϸ�
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}

	//����Ҫɾ����Ԫ�ر�����e��
	e = L.elem[i - 1];

	//3 ����i��λ�õ�Ԫ������ǰ��1λ
	for (int j = i; j <= L.length - 1; j++) //j=i ��ΪҪ������Ԫ�� �������±���(i-1)+1
	{
		L.elem[j - 1] = L.elem[j];
	}

	//4 ��-1
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
