#include <iostream>
#include <thread>

void cul(int, int, int, int*);

int main()
{
	const int threads = 8;

	const int n = 10;
	const int i = 10;

	int **array = new int*[n];
	for (int m = 0; m < n; m++)
	{
		array[m] = new int[i];
	}

	int *array_p[n];
	for (int m = 0; m < n; m++)
	{
		array_p[m] = &array[m][0];
	}

	char a;
	for (int m = 0; m < n; m++)
	{
		a = 'th' + m;
		std::thread a(cul, m, n, i, array_p[0]);
	}
	std::thread::join;
	
	
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < i; b++)
		{
			std::cout << array[a][b] << "," << std::flush;
		}
		std::cout << "" << std::endl;
	}
	

	for (int m = 0; m < n; m++)
	{
		delete[]  array[m];
	}
	delete[] array;
}

void cul(int n_0, int n_1, int i_1, int* array)
{
	for (int i = 0; i < i_1; i++)
		{
			*(array + i) = n_0 * i;
		}
	return;
}