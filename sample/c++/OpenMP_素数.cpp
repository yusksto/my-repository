#include <iostream>
#include <cmath>
#include <omp.h>

int main()
{
	for (int i = 1000000000; i < 1001000000; i++)
	{
		bool tf = true;
		int a = sqrtf(i);

#pragma omp parallel for
		for (int j = 2; j < a; j++)
		{
			if (i % j == 0)
			{
				tf = false;
				break;
			}
		}
		if (tf)
		{
			std::cout << i << std::endl;
		}
	}
}
