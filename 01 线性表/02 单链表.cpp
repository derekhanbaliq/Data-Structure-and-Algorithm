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
//������ָ��p��Lnode *p = LinkList p �����ú��߱������� ǰ�߱������ָ��

/*
 * 1��ÿ�������㣬���ܻᷢ��ɾ���������������ע���˽��ṹ���е�ָ��϶��᲻�ϵķ����仯������������Ķ���һ��Ҫ��ָ�����Խ����м�ӷ���
 * 2���ڴ���ͷ���ָ������ú���ʱ���ں����Ĳ��������У����ͷ�������ڴ�ռ䣬��������޸ġ���������Ҫ��ָ��ͷ���ָ���ָ������Ϊ�����Ĳ����� - �����ǵĺ����У��� ���� �� ��Ҫ�޸ĵĲ���
 * ��������������������������������
 * ԭ�����ӣ�https ://blog.csdn.net/ivebeenready/article/details/50551853
*/

//�������L - �Զ����㷨1
void FillList(LinkList& L)
{
	Lnode* p; //ջ������
	//Lnode* p = new Lnode; Ҫ���ö��� ���ֶ������ֶ��ͷż��� - ���Ҫdelete

	p = L; //��ȡ����L��ͷָ��

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			p->data = 971105; //ͷ���������Ϊinfo
		}
		else
		{
			p->data = 100 - 10 * i; //whatever
		}
		
		p->next = new Lnode;

		p = p->next; //��λ
	}

	p->next = NULL; //��������L���һ������next Ҫ�ֶ���ֵNULL ����������ָ!
}

//��ӡ����L - �Զ����㷨2
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
Status DestroyList(LinkList& L)
{
	Lnode* p; //����һ��������͵�ָ�����
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
	Lnode* p, * q; //��������������͵�ָ�����

	p = L->next; //pָ��ͷ���ָ����

	while (p) //while (p != NULL) û����β
	{
		q = p->next; //qָ����һ�����
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

	p = L->next; //pָ���һ�����
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

//�ڵ�����L�е�i��Ԫ��֮ǰ��������Ԫ��e
Status ListInsert(LinkList& L, int i, ElemType e)
{
	Lnode* p = L;
	int j = 0;

	while (p && j < i - 1) //Ѱ�ҵ�i-1����� pָ��i-1���
	{
		p = p->next;
		j++; //++j
	}

	if (!p || j > i - 1) //p==NULL(j>��+1) or j<1 ����㲻����
	{
		return ERROR;
	}

	Lnode* s = new Lnode; //�����½��
	s->data = e;
	s->next = p->next; //��ߵ�����
	p->next = s; //ǰ�ߵ����� s�ǵ�ַ��

	return OK;
}

//��������L�е�i��Ԫ��ɾ��
Status ListDelete(LinkList& L, int i, ElemType& e)
{
	Lnode* p = L; //��ͷ��㿪ʼ��
	Lnode* q;
	int j = 0;

	while (p->next && j < i - 1) //Ѱ�ҵ�i����� ����pָ����ǰ��
	{
		p = p->next;
		j++;
	}

	if (!(p->next) || j > i - 1) //С��0 ����n
	{
		return ERROR;
	}

	q = p->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
	p->next = q->next; //p->next->next
	e = q->data;

	delete q; //�ͷ�ɾ�����Ŀռ�

	return OK;
}

//ͷ�巨����������L
void CreateHeadList(LinkList& L, int n)
{
	L = new Lnode;

	L->next = NULL; //�Ƚ���һ����ͷ���ĵ�����

	for (int i = n; i > 0; --i)
	{
		Lnode* p = new Lnode; //�����½�� p=(Lnode*)malloc(sizeof(Lnode));
		p->data = i; //����Ԫ��ֵ cin >> p->data; //scanf(&p->data); whatever
		
		p->next = L->next; //���뵽��ͷ
		L->next = p;
	}
}

//β�巨����������L
void CreateTailList(LinkList& L, int n)
{
	L = new Lnode;
	Lnode* r; //βָ�� һ�����

	L->next = NULL;

	r = L; //βָ��rָ��ͷ���

	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		p->data = i + 1; //cin >> p->data;

		p->next = NULL;
		r->next = p; //���뵽��β
		r = p; //ָ���µ�β���
	}
}

int main(void)
{
	LinkList list, headList, tailList;
	int s, len, i;
	ElemType e;
	Lnode* ptr;
	LinkList Ta, Tb, Tc;

	cout << "LinkList test" << endl << endl;

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
	cout << "list len = " << len << endl << endl;

	//��ȡ��n��Ԫ��
	s = GetElem(list, 4, e);
	cout << "get elem = " << s << endl;
	cout << "e = " << e << endl << endl;

	//����Ԫ��
	ptr = LocateElemAddress(list, -40);
	cout << "locate elem address ptr = " << ptr << endl << endl; //���ص�ַ
	i = LocateElemIndex(list, 60);
	cout << "locate elem index i = " << i << endl << endl; //����index

	//����
	s = ListInsert(list, 8, 666);
	cout << "list insert = " << s << endl;
	PrintList(list);

	//ɾ��
	s = ListDelete(list, 8, e);
	cout << "list insert = " << s << endl;
	PrintList(list);

	//��ղ���ӡ
	s = ClearList(list);
	cout << "clear list = " << s << endl;
	PrintList(list);
	cout << "over" << endl << endl;
	
	//����
	s = DestroyList(list);
	cout << "destroy list = " << s << endl << endl;

	//ͷ�巨����������
	CreateHeadList(headList, 5); 
	PrintList(headList);
	s = DestroyList(headList);
	//cout << "destroy list = " << s << endl << endl;

	//β�巨����������
	CreateTailList(tailList, 10);
	PrintList(tailList);
	s = DestroyList(tailList);
	//cout << "destroy list = " << s << endl << endl;

	//�����б�ͽ��ͨ���� Lnode * �� LinkList ������Lnode����ָ���ȡ��ַ& ���鷳
	//Lnode* test1;
	//test1->data = 1;
	//test1->next = list;
	//Lnode test2;
	//test2.data = 1;
	//test2.next = list;

	return 0;
}
