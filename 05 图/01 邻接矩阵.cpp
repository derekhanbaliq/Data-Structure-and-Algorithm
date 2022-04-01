#include <iostream>

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

typedef int Status;

//�ڽӾ���

#define MaxInt 32767	//��ʾ����ֵ ��infinity
#define MVNum 100		//��󶥵���

typedef char VerTexType;	//�趥�����������Ϊ�ַ���
typedef int ArcType;		//����ߵ�Ȩֵ����Ϊ����

typedef struct
{
	VerTexType vexs[MVNum];		//�����
	ArcType arcs[MVNum][MVNum]; //�ڽӾ���
	int vexnum, arcnum;			//ͼ�ĵ�ǰ�����ͱ���
}AMGraph; //Adjacency Matrix Graph

bool visited[MVNum] = {};

//�����ڽӾ����ʾ������������
Status CreateUDN(AMGraph& G)
{
	cin >> G.vexnum >> G.arcnum; //�����ܶ����� �ܱ���

	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vexs[i]; //������������Ϣ
	}

	for (int i = 0; i < G.vexnum; ++i) //������������Ϣ
	{
		for (int j = 0; i < G.vexnum; ++j)
		{
			G.arcs[i][j] = MaxInt; //�ߵ�Ȩֵ����Ϊ����ֵ
		}
	}

	VerTexType v1, v2;
	int w;

	for (int k = 0; k = G.arcnum; ++k) //�����ڽӾ���
	{
		cin >> v1 >> v2 >> w;

		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2); //ȷ��v1��v2��G�е�λ��

		G.arcs[i][j] = w; //��<v1, v2>��Ȩֵ��Ϊw
		G.arcs[i][j] = G.arcs[j][i]; //��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw
	}

	return OK;
}

//ͼG�в��Ҷ���u ���ڷ��ض�����е��±� ���򷵻�-1
int LocateVex(AMGraph G, VerTexType u)
{
	int i;

	for (i = 0; i < G.vexnum; ++i)
	{
		if (u == G.vexs[i])
		{
			return i;
		}
	}

	return -1;
}

//�ڽӾ��� ������ȱ���
void DFS(AMGraph G, int v)
{
	cout << v;
	visited[v] = true; //���ʵ�v������

	for (int w = 0; w < G.vexnum; w++) //���μ���ڽӾ���v���ڵ���
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
		{
			DFS(G, w);
		}
		//w��v���ڽӵ� ���wδ���� ��ݹ����DFS
	}
}

int main01(void)
{
	;

	return 0;
}
