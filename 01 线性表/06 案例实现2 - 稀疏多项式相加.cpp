#include <iostream>

using namespace std;

typedef struct Pnode 
{
	float coef; //系数
	int expn; //指数
	struct Pnode* next; //指针域
}Pnode, *Polynomial;

void CreatePoly(Polynomial& P, int n)
{
	Pnode* p = new Pnode;
	
	P->next = NULL;

	for (int i = 1; i <= n; ++i)
	{
		Pnode* s = new Pnode; //s 输入结点
		Pnode* pre = P; //pre 用于保存q的前驱 初值为头结点
		Pnode* q = P->next; //q 当前结点 指向首元结点

		cin >> s->coef >> s->expn;

		while (q && q->expn < s->expn) //找到第一个大于输入项指数的项*q
		{
			pre = q; 
			q = q->next;
		}

		s->next = q; //将输入项s插入到q和其前驱结点pre之间
		pre->next = s;
	}
}

int main(void)
{
	cout << "TBD..." << endl;


	return 0;
}
