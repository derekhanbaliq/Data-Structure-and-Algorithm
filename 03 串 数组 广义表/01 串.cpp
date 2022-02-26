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
#define CHUNKSIZE	80	//��Ĵ�С�û��Զ���

typedef struct
{
	char ch[MAXLEN + 1];	//�洢����һά���� ��[1]��ʼ�� [0]���в���
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

//KMP�㷨
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

int main(void)
{


	return 0;
}

