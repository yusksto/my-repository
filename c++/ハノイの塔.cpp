#include <iostream>

int func(int N, int i, int n) {
	if (N == i)
	{
		return n;
	}
	else
	{
		n = func(N, i + 1, 2 * n + 1);
	}
}

int main()
{
	int N = 20;
	for (int i = 1; i < N + 1; i++)
	{
		std::cout << i << "	" << func(i, 1, 1) << std::endl;
	}	
}