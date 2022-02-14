#include <iostream>

using namespace std;

typedef struct Pnode 
{
	float coef; //ϵ��
	int expn; //ָ��
	struct Pnode* next; //ָ����
}Pnode, *Polynomial;

void CreatePoly(Polynomial& P, int n)
{
	Pnode* p = new Pnode;
	
	P->next = NULL;

	for (int i = 1; i <= n; ++i)
	{
		Pnode* s = new Pnode; //s ������
		Pnode* pre = P; //pre ���ڱ���q��ǰ�� ��ֵΪͷ���
		Pnode* q = P->next; //q ��ǰ��� ָ����Ԫ���

		cin >> s->coef >> s->expn;

		while (q && q->expn < s->expn) //�ҵ���һ������������ָ������*q
		{
			pre = q; 
			q = q->next;
		}

		s->next = q; //��������s���뵽q����ǰ�����pre֮��
		pre->next = s;
	}
}

int main(void)
{
	cout << "TBD..." << endl;


	return 0;
}
