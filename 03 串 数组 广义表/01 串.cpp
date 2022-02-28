#include <iostream>

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

typedef int Status;

#define MAXLEN		20
#define CHUNKSIZE	80	//块的大小用户自定义

typedef struct
{
	char ch[MAXLEN + 1];	//存储串的一维数组 从[1]开始数 [0]空闲不用 - 或者如《大话数据结构》只要char[] char[0]存长度
	int length;				//串的当前长度
} SString;

//BF算法 - Brutal Force
int Index_BF(SString S, SString T, int pos)
{
	int i = pos, j = 1;
	
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			++i;
			++j; //主串和子串依次匹配下一个字符
		}
		else
		{
			i = i - j + 2;
			j = 1; //主串 子串指针回溯 重新开始下一次匹配
		}
	}

	if (j >= T.length)
	{
		return i - T.length; //返回匹配的第一个字符的下标
	}
	else
	{
		return 0; //模式匹配不成功
	}
}

//串打印
void PrintSString(SString str)
{
	cout << "string = ";
	for (int i = 1; i <= str.length; i++)
	{
		cout << str.ch[i];
	}
	cout << endl << endl;
}

//计算当前要匹配的串T的next数组
void get_next(SString T, int *next)
{
	int i, j;

	i = 1;
	j = 0;
	next[1] = 0;

	//while (i < T.ch[0]) //T.ch[0]表示队长
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j]) //T.ch[i]表示后缀的单个字符 T.ch[j]表示前缀的单个字符
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j]; //若字符不相同 则j值回溯
		}
	}
}
//改良版get_next
void get_nextval(SString T, int nextval[])
{
	int i = 1;
	int j = 0; 
	nextval[1] = 0;

	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;

			if (T.ch[i] != T.ch[j]) //很难理解 不需理解透 会例题就可
			{
				nextval[i] = j;
			}
			else
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j];
		}
	}
}
//KMP算法 - get_next / get_nextval
int Index_KMP(SString S, SString T, int pos)
{
	int i = pos;
	int j = 1;
	int next[MAXLEN] = {};

	//get_next(T, next); //对串T做分析 得到next数组
	get_nextval(T, next);

	while (i <= S.length && j <= T.length) //i < S的长度 且 j < T的长度
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j]; //i不变 j后退
		}
	}

	if (j > T.length)
	{
		return i - T.length; //匹配成功
	}
	else
	{
		return 0; //返回不匹配标志
	}
}



int main01(void)
{
	SString S, T;
	int index;

	//S赋值
	for (int i = 1; i < 13; i++)
	{
		S.ch[i] = 'a';
	}
	S.ch[13] = 'b';
	S.ch[14] = 'c';
	for (int i = 15; i < MAXLEN + 1; i++)
	{
		S.ch[i] = 'a';
	}
	S.length = MAXLEN;
	//S.ch[0] = S.length;

	//S打印
	PrintSString(S);

	//T赋值 abc
	T.ch[1] = 'a';
	T.ch[2] = 'b';
	T.ch[3] = 'c';
	T.length = 3;
	//T.ch[0] = T.length;

	//T打印
	PrintSString(T);

	index = Index_BF(S, T, 5);
	cout << "index = " << index << endl;

	index = Index_KMP(S, T, 5);
	cout << "index = " << index << endl;

	return 0;
}
