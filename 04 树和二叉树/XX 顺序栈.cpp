#include "stack.h"

//顺序栈S的初始化
Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSSIZE]; //or 
	// S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));

	if (!S.base)
	{
		exit(OVERFLOW); //存储分配失败
	}

	S.top = S.base; //栈顶指针=栈底指针
	S.stacksize = MAXSSIZE;

	return OK;
}

//判断顺序栈S是否为空
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

//打印顺序栈S - 自定义函数1
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

//求顺序栈S长度
int StackLength(SqStack S)
{
	return S.top - S.base;
}

//清空顺序栈S
Status ClearStack(SqStack S)
{
	if (S.base)
	{
		S.top = S.base;
	}

	return OK;
}

//销毁顺序栈S
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

//顺序栈S的入栈
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base == S.stacksize) //栈满
	{
		return OVERFLOW;
	}

	*S.top++ = e; //*S.top = e; S.top++;

	return OK;
}

//顺序栈S的出栈
Status Pop(SqStack& S, SElemType& e)
{
	if (IsStackEmpty(S))
	{
		return UNDERFLOW;
	}

	e = *--S.top; // S.top--; e = *S.top; top指向的是顶端元素++的位置！

	return OK;
}
