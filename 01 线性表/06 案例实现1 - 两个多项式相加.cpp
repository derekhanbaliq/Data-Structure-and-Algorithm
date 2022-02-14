#include "SqList.h"

using namespace std;

//填充顺序表Poly1
void FillPoly1(SqList& L)
{
	for (int i = 0; i < MAXSIZE - 2; i++)
	{
		L.elem[i] = ElemType(ElemType(pow(i, 2)) - 4 * i + 4); //anyway
	}
	L.length = MAXSIZE - 2;
}

//填充顺序表Poly2
void FillPoly2(SqList& L)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		L.elem[i] = ElemType(ElemType(pow(i, 3))); //anyway
	}
	L.length = MAXSIZE;
}

//打印多项式L
void PrintPoly(SqList L)
{
	cout << "print polynomial: " << endl;

	//打印索引号
	cout << "n degree: ";
	for (int i = 0; i < L.length; i++)
	{
		cout << i << "\t"; //从0开始 - 多项式
	}
	cout << endl;

	cout << "elements: ";
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == 0)
		{
			cout << " " << "\t";
		}
		else
		{
			cout << L.elem[i] << "\t";
		}
	}
	cout << endl;
	cout << "length: " << L.length << endl << endl;
}

int main0601()
{
	SqList poly1, poly2, poly3;
	int i = 0;

	InitList(poly1);
	FillPoly1(poly1);
	PrintPoly(poly1);

	InitList(poly2);
	FillPoly2(poly2);
	PrintPoly(poly2);

	InitList(poly3);
	PrintPoly(poly3);
	
	while (i < poly1.length && poly2.length)
	{
		poly3.elem[i] = poly1.elem[i] + poly2.elem[i];
		i++;
	}

	while (i < poly1.length)
	{
		poly3.elem[i] = poly1.elem[i];
		i++;
	}

	while (i < poly2.length)
	{
		poly3.elem[i] = poly2.elem[i];
		i++;
	}

	poly3.length = i;

	PrintPoly(poly3);

	DestoryList(poly1);
	DestoryList(poly2);

	return 0;
}