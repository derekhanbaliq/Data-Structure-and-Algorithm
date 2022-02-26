#include <iostream>

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

typedef int Status;

#define MAXLEN		255
#define CHUNKSIZE	80	//块的大小用户自定义

typedef struct
{
	char ch[MAXLEN + 1];	//存储串的一维数组 从[1]开始数 [0]空闲不用
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

//KMP算法
int Index_KMP(SString S, SString T, int pos)
{
	int i = pos;
	int j = 1;
	int next[MAXLEN] = {};

	while (i < S.length && j < T.length)
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

void get_nextval(SString T, int nextval[])
{
	int i = 1;
	nextval[1] = 0;
	int j = 0;

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

int main(void)
{


	return 0;
}

