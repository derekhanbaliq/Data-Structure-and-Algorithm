#include <iostream>
#include "config.h"

using namespace std;

#define TRUE			1
#define FALSE			0

#define OK				1
#define ERROR			0
#define OVERFLOW		-1
#define UNDERFLOW		-2

//顺序存储结构 - 一维结构数组
//结点类型定义
typedef struct
{
	int weight;
	int parent, lch, rch;
}HTNode, * HuffmanTree;

//构造哈夫曼树--哈夫曼算法
void CreateHuffmanTree(HuffmanTree HT, int n)
{
	if (n <= 1)
	{
		return;
	}
	
	//1 初始化HT[1...2n-1]的lch=rch=parent=0

	int m = 2 * n - 1; //数组共2n-1个元素
	HT = new HTNode[m + 1]; //0号元素未用，HM[m]表示根结点

	for (int i = 1; i <= m; ++i) //将2n-1个元素的lch, rch, parent置0
	{
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}

	//2 初始化n个叶子结点 置HT[1...n]的weight值

	for (int i = 1; i <= n; ++i) //输入前n个元素的weight值
	{
		cout << "input weight: ";
		cin >> HT[i].weight;
	}

	//初始化结束 下面开始建立哈夫曼树

	//3 进行以下n-1次合并 依次产生n-1个结点 HT[i] i=n+1...2n-1

	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;

		Select(HT, i - 1, s1, s2); //在HT[k](1<=k<=i-1)中选择两个其双亲域为0 且权值最小的结点 并返回其在HT中的序号s1, s2
		
		HT[s1].parent = s1;
		HT[s2].parent = s2; //s1, s2分别作为i的左右孩子
		HT[i].weight = HT[s1].weight + HT[s2].weight; //i的权值为左右孩子权值之和
	}
}

void Select(HuffmanTree HT, int n, int s1, int s2)
{
	;
}

int main(void)
{
	HuffmanTree H;

	return 0;
}
