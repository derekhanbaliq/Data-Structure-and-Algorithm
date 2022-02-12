#include "SqList.h"
#include "SqListUnion.h"

using namespace std;

//�����ϲ� ��˳���ʵ��
void MergeSqList(SqList La, SqList Lb, SqList& Lc)
{
	ElemType* pa = La.elem;
	ElemType* pb = Lb.elem; //�ֱ�ָ��������ĵ�һ��Ԫ��
	ElemType* pc;
	ElemType* paLast = La.elem + La.length - 1;
	ElemType* pbLast = Lb.elem + Lb.length - 1; //�ֱ�ָ������������һ��Ԫ��

	Lc.length = La.length + Lb.length;
	Lc.elem = new ElemType[Lc.length]; //�����±������ռ�
	pc = Lc.elem; //ָ��Lc�ĵ�һ��Ԫ��

	while (pa <= paLast && pb <= pbLast) //�������Ƿǿ�
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++; //�ȸ�ֵ������++
		}
		else
		{
			*pc++ = *pb++;
		}
	}

	while (pa <= paLast) //La�л���ʣ��
	{
		*pc++ = *pa++;
	}

	while (pb <= pbLast) //Lb�л���ʣ��
	{
		*pc++ = *pb++;
	}
}

int main06(void)
{
	SqList La, Lb, Lc;

	InitList(La);
	FillListLa(La);
	PrintList(La);

	InitList(Lb);
	FillListLb(Lb);
	PrintList(Lb);

	InitList(Lc);
	MergeSqList(La, Lb, Lc);
	PrintList(Lc);

	DestoryList(La);
	DestoryList(Lb);
	DestoryList(Lc);
	
	return 0;
}
