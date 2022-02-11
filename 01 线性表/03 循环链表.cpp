#include <iostream>
#include <stdlib.h> //malloc & free

using namespace std;

//general define ��01�ļ����Ѿ�������Բ���д 
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

#define FILL_SIZE		10

//typedef ��������
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;		//������
	struct Lnode* next; //ָ���� - �Լ������Լ� Ƕ�׶���
} Lnode, * LinkList;	//���������������ͣ� ��Lnode��������ΪLnode LinkListΪָ��ṹ��Lnode��ָ������
//��������L��LinkList L;
//����ڵ�ָ��p��Lnode *p = LinkList p �����ú��߱������� ǰ�߱����ڵ�ָ��

//��ӡ����L - �Զ����㷨1 - ��02���Ѷ���
void PrintCircularList(LinkList l) //���ı�ʵ�� ���Բ�������
{
	while (l->next != NULL)
	{
		cout << l->data << "\t";
		cout << l->next << endl;

		l = l->next; //��λ
	}

	cout << endl;
}

//ͷ�巨����ѭ������ - �Զ����㷨2
void CreateCircularHeadList(LinkList& L, int n)
{
	L = new Lnode;
	Lnode* q;

	L->data = 100;
	L->next = NULL;

	for (int i = n; i > 0; --i)
	{
		Lnode* p = new Lnode; //�����½�� p=(Lnode*)malloc(sizeof(Lnode));
		p->data = i * 10; //����Ԫ��ֵ cin >> p->data; //scanf(&p->data); whatever

		p->next = L->next; //���뵽��ͷ
		L->next = p;
	}

	q = L->next;

	for (int i = 0; i < n - 1; i++) //�ҵ�β���
	{
		q = q->next;
	}

	q->next = L; //β��� ָ���Լ���ͷ���ѭ������
}

//β�巨����ѭ������ - �Զ����㷨3
void CreateCircularTailList(LinkList& L, int n)
{
	L = new Lnode;
	Lnode* r; //βָ�� һ�����

	L->data = 888;
	L->next = NULL;

	r = L; //βָ��rָ��ͷ���

	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		p->data = i; //cin >> p->data;

		p->next = NULL;
		r->next = p; //���뵽��β
		r = p; //ָ���µ�β���
	}

	r->next = L; //ѭ������
}

//��βָ��ѭ������ĺϲ�
LinkList ConnectCircularList(LinkList Ta, LinkList Tb) //����Ta��Tb���Ƿǿյĵ�ѭ������
{
	Lnode* p = Ta->next; //1 p���ͷ���

	Ta->next = Tb->next->next; //2 Tb��ͷ����Ta��β

	delete Tb->next; //3 �ͷ�Tb��ͷ���

	Tb->next = p; //4 �޸�ָ��

	return Tb;
}

int main03(void)
{
	LinkList Ta, Tb, Tc;

	cout << "\t\t\t\t\t\t!!!!Warning!!!!\t\t\t\t\t\t" << endl << endl;


	//ͷ�巨����ѭ������Ta
	CreateCircularHeadList(Ta, 4);
	//PrintCircularList(Ta); //��ѭ����ӡ
	//s = DestroyList(Ta); //ѭ������ɾ�����

	//β�巨����ѭ������Tb
	CreateCircularTailList(Tb, 8);
	//PrintCircularList(Tb); //��ѭ����ӡ

	//ѭ������ĺϲ���Tc
	Tc = ConnectCircularList(Ta, Tb);
	PrintCircularList(Tc); //��ѭ����ӡ

	return 0;
}
