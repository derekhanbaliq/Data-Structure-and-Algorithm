#pragma once
#include <iostream>

using namespace std;

//general define ��01�ļ����Ѿ�������Բ���д 
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

#define FILL_SIZE		10

//typedef ��������
typedef int Status;
typedef int ElemType;

typedef struct Lnode
{
	ElemType data;		//������
	struct Lnode* next; //ָ���� - �Լ������Լ� Ƕ�׶���
} Lnode, * LinkList;	//���������������ͣ� ��Lnode��������ΪLnode LinkListΪָ��ṹ��Lnode��ָ������
//��������L��LinkList L;
//����ڵ�ָ��p��Lnode *p = LinkList p �����ú��߱������� ǰ�߱����ڵ�ָ��

//�������L - �Զ����㷨1
void FillList(LinkList& L);

//��ӡ����L - �Զ����㷨2
void PrintList(LinkList L);

//��ʼ������L
Status InitList(LinkList& L);

//�ж�����L�Ƿ�Ϊ�� - �����㷨1
Status IsEmpty(LinkList L);

//���ٵ�����L - �����㷨2
Status DestroyList(LinkList L);

//��յ�����L - �����㷨3
Status ClearList(LinkList& L);

//������L�� - �����㷨4
int ListLength(LinkList L);

//ȡ������L�е�i��Ԫ�ص�����
Status GetElem(LinkList L, int i, ElemType& e);

//�ڵ������в���ֵΪe������Ԫ��
//�ҵ�����L��ֵΪe������Ԫ�ص�ַ ʧ�ܷ���NULL
Lnode* LocateElemAddress(LinkList L, ElemType e);

//�ڵ������в���ֵΪe������Ԫ�ص�λ�����
//�ҵ�����L��ֵΪe������Ԫ����� ʧ�ܷ���NULL
int LocateElemIndex(LinkList L, ElemType e);

//�ڵ�����L�е�i��Ԫ��֮ǰ��������Ԫ��e
Status ListInsert(LinkList& L, int i, ElemType e);

//��������L�е�i��Ԫ��ɾ��
Status ListDelete(LinkList& L, int i, ElemType& e);

//ͷ�巨����������L
void CreateHeadList(LinkList& L, int n);

//β�巨����������L
void CreateTailList(LinkList& L, int n);