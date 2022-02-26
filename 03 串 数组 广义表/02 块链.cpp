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
#define CHUNKSIZE	80	//块的大小用户自定义

typedef struct Chunk
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
} Chunk;					//块链结点

typedef struct
{
	Chunk* head, * tail;	//串的头指针和尾指针
	int curlen;				//串的当前长度
} LString;					//字符串的块链结构



int main02(void)
{


	return 0;
}

