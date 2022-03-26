#pragma once
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





