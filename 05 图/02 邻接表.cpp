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

//�ڽӱ�

#define MVNum 100		//��󶥵���

typedef char VerTexType;	//�趥�����������Ϊ�ַ���
typedef int OtherInfo;

//����Ľ��ṹ
typedef struct VNode
{
	VerTexType data;	//������Ϣ
	ArcNode* firstarc;	//ָ���һ�������ö���ıߵ�ָ��
}VNode, AdjList[MVNum]; //AdjList��ʾ�ڽӱ�����

//��(��)�Ľ��ṹ
typedef struct ArcNode	//�߽��
{
	int adjvex;					//�ñ���ָ��Ķ����λ��
	struct ArcNode* nextarc;	//ָ����һ���ߵ�ָ��
	OtherInfo info;				//�ͱ���ص���Ϣ
}ArcNode;

//ͼ�Ľṹ����
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;	//ͼ�ĵ�ǰ�������ͻ���
}ALGraph;

int visited[MVNum];

//�����ڽӱ��ʾ������������
Status CreateUDG(ALGraph& G)
{
	cin >> G.vexnum >> G.arcnum; //�����ܶ����� �ܱ���

	for (int i = 0; i < G.vexnum; ++i) //������� �����ͷ����
	{
		cin >> G.vertices[i].data; //���붥��ֵ
		G.vertices[i].firstarc = NULL; //��ʼ����ͷ����ָ����
	}

	VerTexType v1, v2;

	for (int k = 0; k < G.arcnum; ++k) //������� �����ڽӱ�
	{
		cin >> v1 >> v2; //����һ������������������
		
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);

		//���ڽӱ�ʡ��p1����
		ArcNode* p1 = new ArcNode; //�����µı߽��p1
		p1->adjvex = j; //�ڽӵ����Ϊj
		p1->nextarc = G.vertices[i].firstarc; //ͷ�巨
		G.vertices[i].firstarc = p1; //���½��*p1���붥��vi�ı߱�ͷ��

		//������ʡ��p2����
		ArcNode* p2 = new ArcNode; //�����µı߽��p2
		p2->adjvex = i; //�ڽӵ����Ϊi
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2; //���½��*p2���붥��vj�ı߱�ͷ��
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

//BFS - ������ȱ��� ��ͨͼ
void BFS(ALGraph G, int v)
{
	SqQueue Q;
	int u, w;

	cout << v;
	visited[v] = true; //���ʵ�v������

	InitQueue(Q);

	EnQueue(Q, v); //���

	while (QueueLength(Q) != 0)
	{
		DeQueue(Q, u); //��ͷԪ�س��� ����Ϊu

		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
		{
			if (!visited[w]) //wΪ��δ���ʵ��ڽӶ���
			{
				cout << w;
				visited[w] = true;
				EnQueue(Q, w); //w����
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
