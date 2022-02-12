#include "SqList.h"
#include "SqListUnion.h"

using namespace std;

//有序表合并 用顺序表实现
void MergeSqList(SqList La, SqList Lb, SqList& Lc)
{
	ElemType* pa = La.elem;
	ElemType* pb = Lb.elem; //分别指向两个表的第一个元素
	ElemType* pc;
	ElemType* paLast = La.elem + La.length - 1;
	ElemType* pbLast = Lb.elem + Lb.length - 1; //分别指向两个表的最后一个元素

	Lc.length = La.length + Lb.length;
	Lc.elem = new ElemType[Lc.length]; //开辟新表的数组空间
	pc = Lc.elem; //指向Lc的第一个元素

	while (pa <= paLast && pb <= pbLast) //两个表都是非空
	{
		if (*pa <= *pb)
		{
			*pc++ = *pa++; //先赋值再自身++
		}
		else
		{
			*pc++ = *pb++;
		}
	}

	while (pa <= paLast) //La中还有剩余
	{
		*pc++ = *pa++;
	}

	while (pb <= pbLast) //Lb中还有剩余
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
