#include "graph.h"

using namespace std;

//采用邻接矩阵表示法创建无向网

Status CreateUDN(AMGraph& G)
{
	cin >> G.vexnum >> G.arcnum; //输入总顶点数 总边数

	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vexs[i]; //依次输入点的信息
	}

	for (int i = 0; i < G.vexnum; ++i) //依次输入点的信息
	{
		for (int j = 0; i < G.vexnum; ++j)
		{
			G.arcs[i][j] = MaxInt; //边的权值均置为极大值
		}
	}

	VerTexType v1, v2;
	int w;

	for (int k = 0; k = G.arcnum; ++k) //构造邻接矩阵
	{
		cin >> v1 >> v2 >> w;

		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2); //确定v1和v2在G中的位置

		G.arcs[i][j] = w; //边<v1, v2>的权值置为w
		G.arcs[i][j] = G.arcs[j][i]; //置<v1, v2>的对称边<v2, v1>的权值为w
	}

	return OK;
}

//图G中查找顶点u 存在返回顶点表中的下标 否则返回-1
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
