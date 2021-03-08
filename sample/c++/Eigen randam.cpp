#include <iostream>
#include <cmath>
#include <math.h>

#include "Eigen/Core"

int main()
{
	constexpr auto n = 10;

	Eigen::MatrixXf w = Eigen::MatrixXf::Random(n, n);
	std::cout << w << std::endl;
}

