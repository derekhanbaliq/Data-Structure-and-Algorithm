#include <iostream>

using namespace std;

struct Book
{
	char id[20]; //ISBN
	char name[50]; //书名
	int price; //定价
};

//顺序表定义
typedef struct
{
	Book* elem;
	int length;
} SqList;

//链表定义
typedef struct Lnode
{
	Book data;
	struct Lnode* next;
}Lnode, * LinkList;

int main0603(void)
{
	cout << "TBD..." << endl;

	return 0;
}