#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>



int main()
{
	const char* fileName = "PrimeNumber.dat";

	std::fstream fs;
	fs.open(fileName, std::ios::in | std::ios::out | std::ios::app);
	if (!fs)
	{
		std::cout << "We can't open PrimeNumber.dat.";
		return 0;
	}

	unsigned long n = 0;

	while (!fs.eof())
	{
		fs >> n;
	}

	n++;

	if (n < 2)
	{
		n = 3;
	}

	n--;

	fs.close();
	fs.open(fileName, std::ios::out | std::ios::app);
	if (!fs)
	{
		std::cout << "We can't open PrimeNumber.dat";
		return 0;
	}

	bool judge = true;
	int j = 0;
	for (;; n++)
	{
		j = (int)sqrt(n) + 1;
		for (unsigned long i = 2; i < j; i++)
		{
			if (n % i == 0)
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
			fs << n << std::endl;
			std::cout << n << std::endl;
		}
	}
	fs.close();
	return 0;
}