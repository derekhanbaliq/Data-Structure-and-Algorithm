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





