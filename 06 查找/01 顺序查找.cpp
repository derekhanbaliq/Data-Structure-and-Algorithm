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
typedef int ElemType;
typedef int KeyType;

//����Ԫ�����Ͷ���
typedef struct
{
	KeyType key; //�ؼ�����
	//������
} ElemType;

//˳���ṹ���Ͷ���
typedef struct
{
	ElemType* R; //�����ַ
	int length; //��
}SSTable; //Sequential Search Table

SSTable ST; //����˳���ST

int main(void)
{


	return 0;
}
