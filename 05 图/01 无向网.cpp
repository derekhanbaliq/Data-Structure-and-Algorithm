#include "graph.h"

using namespace std;

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


int main(void)
{
	;

	return 0;
}
