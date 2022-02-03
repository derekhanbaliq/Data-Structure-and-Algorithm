#include <iostream>
#include <stdlib.h> //malloc & free

using namespace std;

//general define ��01�ļ����Ѿ�������Բ���д 
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

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

int main(void)
{
	LinkList list;
	int s;

	s = InitList(list);
	cout << "init status = " << s << endl;

	s = IsEmpty(list);
	cout << "is empty = " << s << endl;


	return 0;
}
