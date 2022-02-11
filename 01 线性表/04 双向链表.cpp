#include <iostream>
#include <stdlib.h> //malloc & free

using namespace std;

//general define 在01文件中已经定义可以不用写 
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

#define FILL_SIZE		10

//typedef 仍需声明
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

//在带头结点的双向循环链表L中第i个位置之前插入元素e
Status InsertDualList(DuLinkList& L, int i, ElemType e)
{
	DuLnode* p;

	if (!(p = GetElemDual(L, i)))
	{
		return ERROR;
	}

	DuLnode* s = new DuLnode;

	s->data = e;

	//要改四个指针！
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
