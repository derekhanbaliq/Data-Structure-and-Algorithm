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
	SElemType* base;	//栈底指针
	SElemType* top;		//栈顶指针
	int stacksize;		//栈可用最大容量
}SqStack;

//顺序栈S的初始化
Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE]; //or 
	// S.base = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));

	if (!S.base)
	{
		exit(OVERFLOW); //存储分配失败
	}

	S.top = S.base; //栈顶指针=栈底指针
	S.stacksize = MAXSIZE;

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

//填充顺序栈S - 自定义函数2
Status FillStack(SqStack& S)
{
	
	for (int i = 0; i < 10; i++)
	{
		*(S.top) = SElemType(2 * i + 3); //结构体指针的解引用！
		S.top++;
	}

	return OK;
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
