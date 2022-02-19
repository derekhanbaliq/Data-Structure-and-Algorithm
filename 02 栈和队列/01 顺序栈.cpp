#include <iostream>

using namespace std;

//general define
#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1

typedef int Status;
typedef int SElemType;

#define MAXSIZE 20

typedef struct
{
	SElemType* base;	//ջ��ָ��
	SElemType* top;		//ջ��ָ��
	int stacksize;		//ջ�����������
}SqStack;

//˳��ջS�ĳ�ʼ��
Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE]; //or 
	// S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));

	if (!S.base)
	{
		exit(OVERFLOW); //�洢����ʧ��
	}

	S.top = S.base; //ջ��ָ��=ջ��ָ��
	S.stacksize = MAXSIZE;

	return OK;
}

//�ж�˳��ջS�Ƿ�Ϊ��
Status IsStackEmpty(SqStack S)
{
	if (S.top == S.base)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//��ӡ˳��ջS - �Զ��庯��1
void PrintStack(SqStack S)
{
	S.top = S.base;
	
	for (int i = 0; i < 10; i++)
	{
		cout << "index\t " << i << " \t";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "data\t " << *S.top << " \t";
		S.top++;
	}
	cout << endl;
}

//���˳��ջS - �Զ��庯��2
Status FillStack(SqStack& S)
{
	
	for (int i = 0; i < 10; i++)
	{
		*(S.top) = SElemType(2 * i + 3); //�ṹ��ָ��Ľ����ã�
		S.top++;
	}

	return OK;
}

//��˳��ջS����
int StackLength(SqStack S)
{
	return S.top - S.base;
}

//���˳��ջS
Status ClearStack(SqStack S)
{
	if (S.base)
	{
		S.top = S.base;
	}

	return OK;
}

//����˳��ջS
Status DestroyStack(SqStack& S)
{
	if (S.base)
	{
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}

	return OK;
}

int main(void)
{
	SqStack stack;
	int s, len;

	s = InitStack(stack);
	cout << "InitStack is " << s << endl;

	s = IsStackEmpty(stack);
	cout << "IsStackEmpty is " << s << endl;

	FillStack(stack);
	PrintStack(stack);

	len = StackLength(stack);
	cout << "StackLength is " << len << endl;

	s = ClearStack(stack);
	cout << "ClearStack is " << s << endl;

	s = DestroyStack(stack);
	cout << "DestroyStack is " << s << endl;

	return 0;
}
