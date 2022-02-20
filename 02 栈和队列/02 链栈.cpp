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

//链栈S的初始化 - 补充算法1
Status InitLinkStack(LinkStack& S)
{
	//S = NULL; //视频中提供的方法 但是似乎可再完善

	S = new StackNode;

	S->data = 0;
	S->next = NULL;

	return OK;
}

//判断链栈S是否为空 - 补充算法2
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

//填充链栈S - 自定义算法1
Status FillLinkStack(LinkStack& S)
{
	//现在的S只是一个指针！

	for (int i = 0; i < 10; i++)
	{
		StackNode* ptr = new StackNode; //创建一个新结点
		
		ptr->data = SElemType(10 * (i + 1));
		cout << "ptr->data = " << ptr->data << " \t";

		ptr->next = S; //ptr->next为空
		S = ptr; //头插法
		cout << "ptr = " << ptr << endl;
	}

	cout << "S = " << S << endl;
	cout << "S->next = " << S->next << endl;

	return OK;
}

//打印链栈S - 自定义算法2
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

//链栈S的入栈
Status LinkStackPush(LinkStack& S, SElemType e)
{
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S; //将新结点插入栈顶

	S = p; //修改栈顶指针

	return OK;
}

//链栈S的出栈
Status LinkStackPop(LinkStack& S, SElemType& e)
{
	StackNode* p = new StackNode;

	if (S == NULL)
	{
		return UNDERFLOW;
	}

	e = S->data;
	p = S; //指针p保存当前S指针
	S = S->next;
	delete p;

	return OK;
}

//取栈顶元素
SElemType GetTop(LinkStack S)
{
	if (S != NULL)
	{
		return S->data;
	}
}

//链栈S的销毁
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
