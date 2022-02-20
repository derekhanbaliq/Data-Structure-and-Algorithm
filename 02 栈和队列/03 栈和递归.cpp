#include <iostream>

using namespace std;

//递归法求解斐波那契数列
long Fib(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}

//循环结构求解斐波那契数列 - 单项递归->循环结构
long FibLoop(int n)
{
	long t1, t2, t3;

	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		t1 = 1;
		t2 = 1;

		for (int i = 3; i <= n; i++)
		{
			t3 = t1 + t2;
			t1 = t2;
			t2 = t3;
		}

		return t3;
	}
}

//递归法求解阶乘
long Fact(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * Fact(n - 1);
	}
}

//循环结构求解阶乘 - 尾递归->循环结构
long FactLoop(int n)
{
	int t = 1;

	for (int i = 1; i <= n; i++)
	{
		t *= i;
	}

	return t;
}

int main03(void)
{
	long solution;

	solution = Fib(6);
	cout << "solution = " << solution << endl;
	solution = FibLoop(6);
	cout << "solution = " << solution << endl;

	solution = Fact(5);
	cout << "solution = " << solution << endl;
	solution = FactLoop(5);
	cout << "solution = " << solution << endl;

	return 0;
}
