#include <iostream>

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

typedef int Status;

#define MAXLEN		255
#define CHUNKSIZE	80	//��Ĵ�С�û��Զ���

typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
} Chunk;					//�������

typedef struct
{
	Chunk* head, * tail;	//����ͷָ���βָ��
	int curlen;				//���ĵ�ǰ����
} LString;					//�ַ����Ŀ����ṹ



int main02(void)
{


	return 0;
}

