#include <iostream>
#include <stdlib.h> //malloc & free

using namespace std;

//general define
#define TRUE		1
#define FALSE		0
#define OK				1
#define ERROR			0
#define INFEASIBLE		-1
#define STACK_OVERFLOW	-2

typedef int Status;

#define MAXSIZE 20

typedef int KeyType;
typedef int InfoType;

typedef struct //����ÿ����¼(����Ԫ��)�Ľṹ
{
	KeyType key; //�ؼ���
	InfoType otherinfo; //����������
}RedType; //Record Type

typedef struct //����˳���Ľṹ
{
	RedType r[MAXSIZE + 1]; //�洢˳�������� r[0]һ�����ڱ��򻺳���
	int length; //˳���ĳ���
}SqList;

int main(void)
{

	return 0;
}
