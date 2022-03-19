#include <iostream>
#include "config.h"

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

//˳��洢�ṹ - һά�ṹ����
//������Ͷ���
typedef struct
{
	int weight;
	int parent, lch, rch;
}HTNode, * HuffmanTree;

typedef char* HuffmanCode;
	
//�����������--�������㷨
void CreateHuffmanTree(HuffmanTree HT, int n)
{
	if (n <= 1)
	{
		return;
	}
	
	//1 ��ʼ��HT[1...2n-1]��lch=rch=parent=0

	int m = 2 * n - 1; //���鹲2n-1��Ԫ��
	HT = new HTNode[m + 1]; //0��Ԫ��δ�ã�HM[m]��ʾ�����

	for (int i = 1; i <= m; ++i) //��2n-1��Ԫ�ص�lch, rch, parent��0
	{
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}

	//2 ��ʼ��n��Ҷ�ӽ�� ��HT[1...n]��weightֵ

	for (int i = 1; i <= n; ++i) //����ǰn��Ԫ�ص�weightֵ
	{
		cout << "input weight: ";
		cin >> HT[i].weight;
	}

	//��ʼ������ ���濪ʼ������������

	//3 ��������n-1�κϲ� ���β���n-1����� HT[i] i=n+1...2n-1

	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;

		Select(HT, i - 1, s1, s2); //��HT[k](1<=k<=i-1)��ѡ��������˫����Ϊ0 ��Ȩֵ��С�Ľ�� ����������HT�е����s1, s2
		
		HT[s1].parent = s1;
		HT[s2].parent = s2; //s1, s2�ֱ���Ϊi�����Һ���
		HT[i].weight = HT[s1].weight + HT[s2].weight; //i��ȨֵΪ���Һ���Ȩֵ֮��
	}
}

void Select(HuffmanTree HT, int n, int s1, int s2)
{
	;
}

//����?!?!
//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC��
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode* & HC, int n)
{
	HC = new HuffmanCode[n + 1]; //����n���ַ������ͷָ��ʸ��
	char* cd = new char[n]; //������ʱ��ű���Ķ�̬����ռ�

	cd[n - 1] = '\0'; //���������

	for (int i = 1; i <= n; ++i) //����ַ������������
	{
		int start = i - 1;
		int c = i; 
		int f = HT[i].parent;

		//��Ҷ�ӽ�㿪ʼ���ϻ��� ֱ�������
		while (f != 0)
		{
			--start; //����һ��start��ǰָһ��λ��

			if (HT[f].lch == c)
			{
				cd[start] = '0';
			}
			else
			{
				cd[start] = '1';
			}

			c = f;
			f = HT[f].parent; //�������ϻ��� �����i���ַ��ı���
		}

		HC[i] = new char[n - start]; //Ϊ��i���ַ����������ռ�
		strcpy(HC[i], &cd[start]); //����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ����
	}

	delete cd; //�ͷ���ʱ�ռ�
}

int main(void)
{
	HuffmanTree H;

	return 0;
}
