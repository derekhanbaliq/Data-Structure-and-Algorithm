#pragma once
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

//sequence list setup
#define MAXSIZE 10

//typedef struct
//{
//	ElemType elem[MAXSIZE];
//	int length;
//} SqList; //��̬����ķ�ʽ

typedef struct
{
	ElemType* elem;
	int length;
} SqList; //��̬����ķ�ʽ ����˳������������

//��ӡ˳���L
void PrintList(SqList L);

//���˳���L - Whatever
void FillList(SqList& L);

//��ʼ��˳���L
Status InitList(SqList& L);

//����˳���L
void DestoryList(SqList& L);

//���˳���L
void ClearList(SqList& L);

//��˳���L�ĳ���
int GetLength(SqList L);

//�ж�˳���L�Ƿ�Ϊ��
int IsEmpty(SqList L);

//����λ��i��ȡ��Ӧλ������Ԫ�ص����� - O(1) �����ȡ ��ʽ�洢������
int GetElem(SqList L, int i, ElemType& e);

//��˳���L�в���ֵΪe������Ԫ�� ���������(�ڼ���Ԫ��)
int LocateElem(SqList L, ElemType e);

//��˳���L�ĵ�i��λ�ò���Ԫ��e
Status ListInsert(SqList& L, int i, ElemType e);

//��˳���L�ĵ�i��λ��ɾ��Ԫ��e
Status ListDelete(SqList& L, int i, ElemType& e);
