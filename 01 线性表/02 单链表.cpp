#include <iostream>

using namespace std;

//general define ��01�ļ����Ѿ�������Բ���д 
#define TRUE		1
#define FALSE		0
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

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

int main(void)
{


	return 0;
}
