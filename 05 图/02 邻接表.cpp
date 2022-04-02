#include <iostream>
#include "queue.h"

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

typedef int Status;

//邻接表

#define MVNum 100		//最大顶点数

typedef char VerTexType;	//设顶点的数据类型为字符型
typedef int OtherInfo;

//顶点的结点结构
typedef struct VNode
{
	VerTexType data;	//顶点信息
	ArcNode* firstarc;	//指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum]; //AdjList表示邻接表类型

//弧(边)的结点结构
typedef struct ArcNode	//边结点
{
	int adjvex;					//该边所指向的顶点的位置
	struct ArcNode* nextarc;	//指向下一条边的指针
	OtherInfo info;				//和边相关的信息
}ArcNode;

//图的结构定义
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;	//图的当前顶点数和弧数
}ALGraph;

int visited[MVNum];

//采用邻接表表示法创建无向网
Status CreateUDG(ALGraph& G)
{
	cin >> G.vexnum >> G.arcnum; //输入总顶点数 总边数

	for (int i = 0; i < G.vexnum; ++i) //输入各点 构造表头结点表
	{
		cin >> G.vertices[i].data; //输入顶点值
		G.vertices[i].firstarc = NULL; //初始化表头结点的指针域
	}

	VerTexType v1, v2;

	for (int k = 0; k < G.arcnum; ++k) //输入各边 构造邻接表
	{
		cin >> v1 >> v2; //输入一条边依附的两个顶点
		
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);

		//逆邻接表省略p1部分
		ArcNode* p1 = new ArcNode; //生成新的边结点p1
		p1->adjvex = j; //邻接点序号为j
		p1->nextarc = G.vertices[i].firstarc; //头插法
		G.vertices[i].firstarc = p1; //将新结点*p1插入顶点vi的边表头部

		//有向网省略p2部分
		ArcNode* p2 = new ArcNode; //生成新的边结点p2
		p2->adjvex = i; //邻接点序号为i
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2; //将新结点*p2插入顶点vj的边表头部
	}

	return OK;
}

int LocateVex(ALGraph G, VerTexType v)
{
	int i;

	for (i = 0; i < G.vexnum; ++i)
	{
		if (v == G.vertices[i].data)
		{
			return i;
		}
	}

	return -1;
}

//BFS - 广度优先遍历 连通图
void BFS(ALGraph G, int v)
{
	SqQueue Q;
	int u, w;

	cout << v;
	visited[v] = true; //访问第v个顶点

	InitQueue(Q);

	EnQueue(Q, v); //入队

	while (QueueLength(Q) != 0)
	{
		DeQueue(Q, u); //队头元素出队 并置为u

		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
		{
			if (!visited[w]) //w为尚未访问的邻接顶点
			{
				cout << w;
				visited[w] = true;
				EnQueue(Q, w); //w进队
			}
		}
	}
}

int FirstAdjVex(ALGraph G, int u)
{
	int v = 0;
	
	return v;
}

int NextAdjVex(ALGraph G, int u, int w)
{
	int v = 0;

	return v;
}

int main(void)
{
	
	
	return 0;
}
