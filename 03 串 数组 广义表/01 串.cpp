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
#define CHUNKSIZE	80	//��Ĵ�С�û��Զ���

typedef struct
{
	char ch[MAXLEN + 1];	//�洢����һά���� ��[1]��ʼ�� [0]���в��� - �����硶�����ݽṹ��ֻҪchar[] char[0]�泤��
	int length;				//���ĵ�ǰ����
} SString;

//BF�㷨 - Brutal Force
int Index_BF(SString S, SString T, int pos)
{
	int i = pos, j = 1;
	
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			++i;
			++j; //�������Ӵ�����ƥ����һ���ַ�
		}
		else
		{
			i = i - j + 2;
			j = 1; //���� �Ӵ�ָ����� ���¿�ʼ��һ��ƥ��
		}
	}

	if (j >= T.length)
	{
		return i - T.length; //����ƥ��ĵ�һ���ַ����±�
	}
	else
	{
		return 0; //ģʽƥ�䲻�ɹ�
	}
}

//����ӡ
void PrintSString(SString str)
{
	cout << "string = ";
	for (int i = 1; i <= str.length; i++)
	{
		cout << str.ch[i];
	}
	cout << endl << endl;
}

//���㵱ǰҪƥ��Ĵ�T��next����
void get_next(SString T, int *next)
{
	int i, j;

	i = 1;
	j = 0;
	next[1] = 0;

	//while (i < T.ch[0]) //T.ch[0]��ʾ�ӳ�
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j]) //T.ch[i]��ʾ��׺�ĵ����ַ� T.ch[j]��ʾǰ׺�ĵ����ַ�
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j]; //���ַ�����ͬ ��jֵ����
		}
	}
}
//������get_next
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

			if (T.ch[i] != T.ch[j]) //������� �������͸ ������Ϳ�
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
//KMP�㷨 - get_next / get_nextval
int Index_KMP(SString S, SString T, int pos)
{
	int i = pos;
	int j = 1;
	int next[MAXLEN] = {};

	//get_next(T, next); //�Դ�T������ �õ�next����
	get_nextval(T, next);

	while (i <= S.length && j <= T.length) //i < S�ĳ��� �� j < T�ĳ���
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j]; //i���� j����
		}
	}

	if (j > T.length)
	{
		return i - T.length; //ƥ��ɹ�
	}
	else
	{
		return 0; //���ز�ƥ���־
	}
}



int main01(void)
{
	SString S, T;
	int index;

	//S��ֵ
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

	//S��ӡ
	PrintSString(S);

	//T��ֵ abc
	T.ch[1] = 'a';
	T.ch[2] = 'b';
	T.ch[3] = 'c';
	T.length = 3;
	//T.ch[0] = T.length;

	//T��ӡ
	PrintSString(T);

	index = Index_BF(S, T, 5);
	cout << "index = " << index << endl;

	index = Index_KMP(S, T, 5);
	cout << "index = " << index << endl;

	return 0;
}
