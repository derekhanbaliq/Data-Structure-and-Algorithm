#include "LinkList.h"

using namespace std;

//β�巨����������Lb �ı�data��
void CreateTailList2(LinkList& L, int n)
{
	L = new Lnode;
	Lnode* r; //βָ�� һ�����

	L->next = NULL;

	r = L; //βָ��rָ��ͷ���

	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		p->data = pow(i, 2) + 5; //cin >> p->data;

		p->next = NULL;
		r->next = p; //���뵽��β
		r = p; //ָ���µ�β���
	}
}

//�����ĺϲ� ������ʵ��
void MergeLinkList(LinkList& La, LinkList& Lb, LinkList& Lc)
{
	Lnode* pa = La->next;
	Lnode* pb = Lb->next;
	Lnode* pc;

	Lc = La;
	pc = Lc; //��La��ͷ�����ΪLc��ͷ���

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

	pc->next = pa ? pa : pb; //����ʣ���

	delete Lb; //�ͷ�Lb��ͷ���
}

int main0503(void)
{
	LinkList La, Lb, Lc;
	Status s;
	
	//ͷ�巨����������
	CreateHeadList(La, 5);
	PrintList(La);

	//β�巨����������
	CreateTailList2(Lb, 5);
	PrintList(Lb);

	MergeLinkList(La, Lb, Lc);
	PrintList(Lc);

	Lc->next = NULL; //ĩλ�����ֶ���NULL ���������

	s = DestroyList(La);
	cout << "destroy list = " << s << endl << endl;
	s = DestroyList(Lc);
	cout << "destroy list = " << s << endl << endl;

	return 0;
}
