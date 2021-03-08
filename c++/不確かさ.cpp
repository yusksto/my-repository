#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <cassert>
#include <conio.h>

int main()
{
	const int N = 10;//データ数
	double x[] = { 3.061666666667,3.031666666667,3.071666666667,3.051666666667,3.051666666667	,3.061666666667,	3.041666666667	,3.001666666667	,2.991666666667	,3.011666666667};

	//平均値計算,
	double x_ = 0;
	for (int i = 0; i < N; i++)
	{
		x_ += x[i];
	}
	x_ /= N;

	//測定値の不確かさ
	double σ = 0;
	for (int i = 0; i < N; i++)
	{
		σ += pow(x[i] - x_, 2);
	}
	σ = sqrt(σ / N);

	//平均値の不確かさ
	double η = 0;
	for (int i = 0; i < N; i++)
	{
		η += pow(x[i] - x_, 2);
	}
	η = sqrt(η / N / (N - 1));

	//情報表示
	std::cout << "データ数 N = " << N << std::endl;
	std::cout << "データ " << std::flush;
	for (int i = 0; i < N; i++)
	{
		std::cout << x[i] << " ," << std::flush;
	}
	std::cout << std::endl << std::endl;
	std::cout << "平均値 x_ = " << x_ << std::endl;
	std::cout << "測定値の不確かさ σ = " << σ << std::endl;
	std::cout << "平均値の不確かさ η = " << η << std::endl;

	return 0;
}
