#include <iostream>

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

typedef int Status;

//邻接矩阵

#define MaxInt 32767	//表示极大值 即infinity
#define MVNum 100		//最大顶点数

typedef char VerTexType;	//设顶点的数据类型为字符型
typedef int ArcType;		//假设边的权值类型为整形

typedef struct
{
	VerTexType vexs[MVNum];		//顶点表
	ArcType arcs[MVNum][MVNum]; //邻接矩阵
	int vexnum, arcnum;			//图的当前点数和边数
}AMGraph; //Adjacency Matrix Graph

bool visited[MVNum] = {};

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

//邻接矩阵 深度优先遍历
void DFS(AMGraph G, int v)
{
	cout << v;
	visited[v] = true; //访问第v个顶点

	for (int w = 0; w < G.vexnum; w++) //依次检查邻接矩阵v所在的行
	{
		if ((G.arcs[v][w] != 0) && (!visited[w]))
		{
			DFS(G, w);
		}
		//w是v的邻接点 如果w未访问 则递归调用DFS
	}
}

int main01(void)
{
	;

	return 0;
}
