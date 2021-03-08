#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>



int main()
{
	const char* fileName = "PrimeNumber.dat";
	std::fstream fs;
	fs.close();
	fs.open(fileName, std::ios::out);
	if (!fs)
	{
		std::cout << "We can't open PrimeNumber.dat";
		return 0;
	}

	unsigned long long n = 1;

	bool judge = true;
	unsigned long long j, k;
	for (;; n++)
	{

		j = pow(2, n) - 1;
		k = pow(2, n - 1);
		std::cout << n << std::endl;
		for (unsigned long long i = 3; i < k; i += 2)
		{
			if (j % i == 0)
			{
				judge = false;
				break;
			}
		}
		if (judge == false)
		{
			judge = true;
		}
		else
		{
			fs << j << std::endl;
			std::cout << "     " << j << std::endl;
		}
	}
	fs.close();
	return 0;
}