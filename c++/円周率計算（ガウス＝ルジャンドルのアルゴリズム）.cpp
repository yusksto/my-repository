#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#include <iomanip>

int main()
{
	std::ofstream ofs;
	ofs.open("data.txt", std::ios::out);

	long double π;

	long double a_0, a_1, b_0, b_1, t_0, t_1, p_0, p_1;
	a_0 = 1.0;
	b_0 = sqrt(2.0) / 2.0;
	t_0 = 0.25;
	p_0 = 1.0;
	
	for (int i = 0; i < 30; i++)
	{
		a_1 = (a_0 + b_0) / 2;
		b_1 = sqrt(a_0 * b_0);
		t_1 = t_0 - p_0 * (a_0 - a_1) * (a_0 - a_1);
		p_1 = 2 * p_0;

		a_0 = a_1;
		b_0 = b_1;
		t_0 = t_1;
		p_0 = p_1;

		π = (a_0 + b_0) * (a_0 + b_0) / (4 * t_0);

		std::cout << i << " " << std::flush;
		std::cout << std::setprecision(30) << π << std::endl;
		ofs << i << " " << std::flush;
		ofs << std::setprecision(30) << π << std::endl;
	}
	return 0;
}

