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

typedef struct DuLnode
{
	ElemType data;		
	struct DuLnode* prior, * next;
} DuLnode, * DuLinkList;

DuLnode* GetElemDual(DuLinkList& L, int i)
{
	//TBD
	DuLnode* p = new DuLnode;
	
	return p;
}

//�ڴ�ͷ����˫��ѭ������L�е�i��λ��֮ǰ����Ԫ��e
Status InsertDualList(DuLinkList& L, int i, ElemType e)
{
	DuLnode* p;

	if (!(p = GetElemDual(L, i)))
	{
		return ERROR;
	}

	DuLnode* s = new DuLnode;

	s->data = e;

	//Ҫ���ĸ�ָ�룡
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return OK;
}

int main(void)
{
	//TBD
	cout << "TBD..." << endl;

	return 0;
}
