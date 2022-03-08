#include "stack.h"

//˳��ջS�ĳ�ʼ��
Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSSIZE]; //or 
	// S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));

	if (!S.base)
	{
		exit(OVERFLOW); //�洢����ʧ��
	}

	S.top = S.base; //ջ��ָ��=ջ��ָ��
	S.stacksize = MAXSSIZE;

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
	int len = S.top - S.base;
	SElemType* ptr = S.base;

	for (int i = 0; i < len; i++)
	{
		cout << "index\t " << i << " \t";
	}
	cout << endl;

	for (int i = 0; i < len; i++)
	{
		cout << "data\t " << *ptr << " \t";
		ptr++;
	}
	cout << endl << endl;
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

//˳��ջS����ջ
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize) //ջ��
	{
		return OVERFLOW;
	}

	*S.top++ = e; //*S.top = e; S.top++;

	return OK;
}

//˳��ջS�ĳ�ջ
Status Pop(SqStack& S, SElemType& e)
{
	if (IsStackEmpty(S))
	{
		return UNDERFLOW;
	}

	e = *--S.top; // S.top--; e = *S.top; topָ����Ƕ���Ԫ��++��λ�ã�

	return OK;
}
