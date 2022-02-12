#include "SqList.h"

#define SMALL_SIZE 5

//�Զ���˳���La��ֵ����
void FillListLa(SqList& L)
{
	for (int i = 0; i < SMALL_SIZE; i++)
	{
		L.elem[i] = ElemType(ElemType(pow(i, 2))); //anyway
	}
	L.length = SMALL_SIZE;
}

//�Զ���˳���Lb��ֵ����
void FillListLb(SqList& L)
{
	for (int i = 0; i < SMALL_SIZE; i++)
	{
		L.elem[i] = ElemType(ElemType(pow(i, 3))); //anyway
	}
	L.length = SMALL_SIZE;
}

//˳���ĺϲ�
void sqListUnion(SqList& La, SqList& Lb)
{
	int LaLen = GetLength(La);
	int LbLen = GetLength(Lb);
	ElemType e;

	for (int i = 1; i <= LbLen; i++)
	{
		GetElem(Lb, i, e);
		if (!LocateElem(La, e))
		{
			ListInsert(La, ++LaLen, e);
		}
	}
}

int main0501(void)
{
	SqList La, Lb;

	InitList(La);
	FillListLa(La);
	PrintList(La);

	InitList(Lb);
	FillListLb(Lb);
	PrintList(Lb);

	sqListUnion(La, Lb);
	PrintList(La);
	PrintList(Lb);

	DestoryList(La);
	DestoryList(Lb);

	return 0;
}
