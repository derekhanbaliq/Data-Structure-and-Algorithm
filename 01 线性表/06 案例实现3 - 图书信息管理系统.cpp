#include <iostream>

using namespace std;

struct Book
{
	char id[20]; //ISBN
	char name[50]; //����
	int price; //����
};

//˳�����
typedef struct
{
	Book* elem;
	int length;
} SqList;

//������
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