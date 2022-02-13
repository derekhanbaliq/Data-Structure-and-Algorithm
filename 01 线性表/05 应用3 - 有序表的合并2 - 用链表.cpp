#include "LinkList.h"

using namespace std;

//尾插法建立单链表Lb 改变data域
void CreateTailList2(LinkList& L, int n)
{
	L = new Lnode;
	Lnode* r; //尾指针 一个标记

	L->next = NULL;

	r = L; //尾指针r指向头结点

	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		p->data = pow(i, 2) + 5; //cin >> p->data;

		p->next = NULL;
		r->next = p; //插入到表尾
		r = p; //指向新的尾结点
	}
}

//有序表的合并 用链表实现
void MergeLinkList(LinkList& La, LinkList& Lb, LinkList& Lc)
{
	Lnode* pa = La->next;
	Lnode* pb = Lb->next;
	Lnode* pc;

	Lc = La;
	pc = Lc; //用La的头结点作为Lc的头结点

	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa ? pa : pb; //插入剩余段

	delete Lb; //释放Lb的头结点
}

int main0503(void)
{
	LinkList La, Lb, Lc;
	Status s;
	
	//头插法建立单链表
	CreateHeadList(La, 5);
	PrintList(La);

	//尾插法建立单链表
	CreateTailList2(Lb, 5);
	PrintList(Lb);

	MergeLinkList(La, Lb, Lc);
	PrintList(Lc);

	Lc->next = NULL; //末位必须手动给NULL 否则崩溃！

	s = DestroyList(La);
	cout << "destroy list = " << s << endl << endl;
	s = DestroyList(Lc);
	cout << "destroy list = " << s << endl << endl;

	return 0;
}
