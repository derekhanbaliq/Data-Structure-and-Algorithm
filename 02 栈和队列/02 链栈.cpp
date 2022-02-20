#include <iostream>

using namespace std;

//general define
#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

typedef int Status;
typedef int SElemType;

#define MAXSIZE 20

typedef struct StackNode
{
	SElemType data;
	StackNode* next;
}StackNode, *LinkStack;

//��ջS�ĳ�ʼ�� - �����㷨1
Status InitLinkStack(LinkStack& S)
{
	//S = NULL; //��Ƶ���ṩ�ķ��� �����ƺ���������

	S = new StackNode;

	S->data = 0;
	S->next = NULL;

	return OK;
}

//�ж���ջS�Ƿ�Ϊ�� - �����㷨2
Status IsLinkStackEmpty(LinkStack S)
{
	if (S == NULL)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

//�����ջS - �Զ����㷨1
Status FillLinkStack(LinkStack& S)
{
	//���ڵ�Sֻ��һ��ָ�룡

	for (int i = 0; i < 10; i++)
	{
		StackNode* ptr = new StackNode; //����һ���½��
		
		ptr->data = SElemType(10 * (i + 1));
		cout << "ptr->data = " << ptr->data << " \t";

		ptr->next = S; //ptr->nextΪ��
		S = ptr; //ͷ�巨
		cout << "ptr = " << ptr << endl;
	}

	cout << "S = " << S << endl;
	cout << "S->next = " << S->next << endl;

	return OK;
}

//��ӡ��ջS - �Զ����㷨2
void PrintLinkStack(LinkStack& S)
{
	StackNode* ptr = new StackNode;

	ptr = S;

	while (ptr->next != NULL)
	{
		cout << ptr->data << " \t";
		ptr = ptr->next;
	}
	cout << endl << endl;
}

//��ջS����ջ
Status LinkStackPush(LinkStack& S, SElemType e)
{
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S; //���½�����ջ��

	S = p; //�޸�ջ��ָ��

	return OK;
}

//��ջS�ĳ�ջ
Status LinkStackPop(LinkStack& S, SElemType& e)
{
	StackNode* p = new StackNode;

	if (S == NULL)
	{
		return UNDERFLOW;
	}

	e = S->data;
	p = S; //ָ��p���浱ǰSָ��
	S = S->next;
	delete p;

	return OK;
}

//ȡջ��Ԫ��
SElemType GetTop(LinkStack S)
{
	if (S != NULL)
	{
		return S->data;
	}
}

//��ջS������
Status DestroyLinkStack(LinkStack& S)
{
	
	while (S->next != NULL)
	{
		StackNode* ptr = new StackNode;
		
		ptr = S;
		S = S->next;
		delete ptr;
	}

	delete S;

	return OK;
}

int main02(void)
{
	LinkStack LS;
	int s;
	SElemType e;

	s = InitLinkStack(LS);
	cout << "InitLinkStack is " << s << endl << endl;

	s = IsLinkStackEmpty(LS);
	cout << "IsLinkStackEmpty is " << s << endl << endl;

	FillLinkStack(LS);
	PrintLinkStack(LS);

	LinkStackPush(LS, 123);
	PrintLinkStack(LS);

	LinkStackPop(LS, e);
	cout << "e = " << e << endl;
	PrintLinkStack(LS);

	e = GetTop(LS);
	cout << "e = " << e << endl << endl;

	s = DestroyLinkStack(LS);
	cout << "DestroyLinkStack is " << s << endl << endl;

	return 0;
}
