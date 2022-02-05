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

//�������L - �Զ��庯��
void FillList(LinkList& L)
{
	Lnode* p;

	p = L; //��������L��ͷָ��

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			L->data = NULL; //ͷָ��������Ϊ��
		}
		else if (i == 1)
		{
			L->data = 971105; //ͷ���������Ϊinfo
		}
		else
		{
			L->data = i; //whatever
		}
		
		L->next = new Lnode;

		L = L->next; //��λ
	}

	L->next = NULL; //��������L���һ���ڵ��next Ҫ�ֶ���ֵNULL ����������ָ!
	
	L = p;
}

//��ӡ����L - �Զ��庯��
void PrintList(LinkList L) //���ı�ʵ�� ���Բ�������
{
	while (L->next != NULL)
	{
		cout << L->data << "\t";
		cout << L->next << endl;

		L = L->next; //��λ
	}

	cout << endl;
}

//��ʼ������L
Status InitList(LinkList& L)
{
	//1 �����½����ͷ��㣬��ͷָ��Lָ��ͷ���
	L = new Lnode;
	//L = (LinkList)malloc(sizeof(Lnode));

	//2 ��ͷ����ָ�����ÿ�
	L->next = NULL;

	return OK;
}

//�ж�����L�Ƿ�Ϊ��
Status IsEmpty(LinkList L)
{
	if (L->next)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//���ٵ�����L
Status DestroyList(LinkList L)
{
	Lnode* p; //����һ���ڵ����͵�ָ�����
	while (L->next) //while(L!=NULL)
	{
		p = L;
		L = L->next;
		delete p;
	}

	return OK;
}

int main(void)
{
	LinkList list;
	int s;

	s = InitList(list);
	cout << "init list = " << s << endl << endl;

	s = IsEmpty(list);
	cout << "is empty = " << s << endl << endl;

	FillList(list);
	PrintList(list);

	s = DestroyList(list);
	cout << "destroy list = " << s << endl << endl;

	return 0;
}
