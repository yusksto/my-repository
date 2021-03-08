#include <iostream>

int main()
{
	const float pi = 3.141592f;
    const int width = 60;
	const int bias = 10;
	const float Δθ = (float)(pi / 10);

	for (float i = 0; i < 2 * pi; i += Δθ)
	{
		for (int j = 0; j < (int)(width * (1 - sin(i)) / 2 + bias); j++)
		{
			std::cout << " " << std::flush;
		}
		std::cout << "*" << std::endl;
	}
}
