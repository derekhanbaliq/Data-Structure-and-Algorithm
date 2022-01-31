#include <iostream>
#include <stdlib.h> //malloc & free

using namespace std;

//general define
#define TRUE		1
#define FALSE		0

#define OK			1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

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
	ElemType *elem;
	int length;
} SqList; //��̬����ķ�ʽ ����˳������������

//��ӡ���Ա�L
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

//������Ա�L - 1, 2, 3... , 20
void FillList(SqList& L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L.elem[i] = pow(i, 2) - 4 * i + 4; //anyway
	}
	L.length = MAXSIZE;
}

//��ʼ�����Ա�L
Status InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE]; //C++ new ��̬����
	//L.elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); //C����malloc��̬�ڴ���� - heap

	if (!L.elem) //L.elem == 0
	{
		exit(OVERFLOW); //�ڴ治�� û�з��䵽��ַ �洢����ʧ�� ������ֵ �������
	}

	L.length = 0; //�ձ���Ϊ0

	return OK;
}

//�������Ա�L
void DestoryList(SqList& L)
{
	if (L.elem) //������ռ�洢�˶��� L����
	{
		delete L.elem; //�ͷŴ洢�ռ�
	}
}

//������Ա�L
void ClearList(SqList& L)
{
	L.length = 0; //������0
}

//�����Ա�L�ĳ���
int GetLength(SqList L)
{
	return (L.length);
}

//�ж����Ա�L�Ƿ�Ϊ��
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


int main(void)
{
	SqList list;
	int box; //just a test space

	InitList(list);
	PrintList(list);

	FillList(list);
	PrintList(list);
	cout << "GetLength(list) = " << GetLength(list) << endl << endl;
	GetElem(list, 6, box);
	cout << "box = " << box << endl << endl;

	ClearList(list);
	PrintList(list);
	cout << "IsEmpty(list) = " << IsEmpty(list) << endl << endl;

	DestoryList(list);

	return 0;
}
