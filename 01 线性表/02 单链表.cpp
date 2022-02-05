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

//�������L - �Զ��庯��1
void FillList(LinkList& L)
{
	Lnode* p;

	p = L; //��������L��ͷָ��

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			L->data = 971105; //ͷ���������Ϊinfo
		}
		else
		{
			L->data = 100 - 10 * i; //whatever
		}
		
		L->next = new Lnode;

		L = L->next; //��λ
	}

	L->next = NULL; //��������L���һ���ڵ��next Ҫ�ֶ���ֵNULL ����������ָ!
	
	L = p;
}

//��ӡ����L - �Զ��庯��2
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

//�ж�����L�Ƿ�Ϊ�� - �����㷨1
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

//���ٵ�����L - �����㷨2
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

//��յ�����L - �����㷨3
Status ClearList(LinkList& L)
{
	Lnode* p, * q; //���������ڵ����͵�ָ�����

	p = L->next; //pָ��ͷ���ָ����

	while (p) //while (p != NULL) û����β
	{
		q = p->next; //qָ����һ���ڵ�
		delete p;
		p = q;
	}
	//�ѳ�ѭ�� p q ��Ϊ��

	L->next = NULL; //ͷָ���ÿ�

	return OK;
}

//������L�� - �����㷨4
int ListLength(LinkList L)
{
	int i = 0;
	Lnode* p;

	p = L->next; //pָ���һ���ڵ�
	while (p) //p != NULL
	{
		i++;
		p = p->next;
	}

	return i;
}

//ȡ������L�е�i��Ԫ�ص�����
Status GetElem(LinkList L, int i, ElemType& e)
{
	Lnode* p = L->next; //ָ��ָ����Ԫ���
	int j = 1;

	while (p && j < i) //p��Ϊ�ջ�δ����i��Ԫ��
	{
		p = p->next;
		j++; //++j; //i = 1; j = ++i; (i=2 j=2)
	}

	if (!p || j > i) //i <= 0 or j > length or p == NULL
	{
		return ERROR;
	}

	e = p->data;

	return OK;
}

//�ڵ������в���ֵΪe������Ԫ��
//�ҵ�����L��ֵΪe������Ԫ�ص�ַ ʧ�ܷ���NULL
Lnode* LocateElemAddress(LinkList L, ElemType e)
{
	Lnode* p = L->next; //ָ��ָ����Ԫ���

	while (p && p->data != e) //p != NULL �� p����������e
	{
		p = p->next;
	}

	//�����δ�ҵ� p��ʱ���Ѿ���NULL��
	return p; //����ָ�����p
}

//�ڵ������в���ֵΪe������Ԫ�ص�λ�����
//�ҵ�����L��ֵΪe������Ԫ����� ʧ�ܷ���NULL
int LocateElemIndex(LinkList L, ElemType e)
{
	Lnode* p = L->next; //ָ��ָ����Ԫ���
	int j = 1;

	while (p && p->data != e)
	{
		p = p->next;
		j++;
	}

	if (p)
	{
		return j;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	LinkList list;
	int s, len, i;
	ElemType e;
	Lnode* ptr;

	//��ʼ��
	s = InitList(list);
	cout << "init list = " << s << endl << endl;
	
	//�ж��Ƿ�Ϊ��
	s = IsEmpty(list);
	cout << "is empty = " << s << endl << endl;

	//��䲢��ӡ
	FillList(list);
	PrintList(list);

	//�鿴����
	len = ListLength(list);
	cout << "len = " << len << endl << endl;

	//��ȡ��n��Ԫ��
	s = GetElem(list, 4, e);
	cout << "s = " << s << endl;
	cout << "e = " << e << endl << endl;

	//����Ԫ��
	ptr = LocateElemAddress(list, -40);
	cout << "ptr = " << ptr << endl << endl; //���ص�ַ
	i = LocateElemIndex(list, 60);
	cout << "i = " << i << endl << endl; //����index

	//��ղ���ӡ
	s = ClearList(list);
	cout << "clear list = " << s << endl;
	PrintList(list);
	cout << "over" << endl << endl;
	
	//����
	s = DestroyList(list);
	cout << "destroy list = " << s << endl << endl;

	return 0;
}
