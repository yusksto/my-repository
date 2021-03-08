#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <cassert>
#include <conio.h>

int main()
{
	const int N = 12;//データ数
	double x[N] = { 0.10007,0.2,0.3,0.4,0.4501,0.5,0.55,0.6,0.65,0.7,0.75,0.7967 };
	double y[N] = { -2.698970004,-2.698970004,-2.522878745,-1.744727495,-1.119186408,-0.493494968,0.050766311,0.554973458,1.033584576,1.510410948,1.999869692,2.478422188 };

	//各数値の計算
	double x_1 = 0, y_1 = 0, x_2 = 0, xy = 0;
	for (int i = 0; i < N; i++)
	{
		x_1 += x[i];        //[x_i]
		y_1 += y[i];        //[y_1]
		x_2 += x[i] * x[i]; //[x_i^2]
		xy += x[i] * y[i];  //[x_i * y_i]
	}

	//係数aと切片bの計算
	double a, b;
	a = (N * xy - x_1 * y_1) / (N * x_2 - x_1 * x_1);
	b = (x_2 * y_1 - x_1 * xy) / (N * x_2 - x_1 * x_1);

	//yの不確かさ計算
	double σ_y = 0;
	for (int i = 0; i < N; i++)
	{
		σ_y += pow(y[i] - (a * x[i] + b), 2);
	}
	σ_y = sqrt(σ_y / (N - 2));

	//a,bの不確かさ計算
	double σ_a, σ_b;
	σ_a = σ_y * sqrt(N / (N * x_2 - pow(x_1, 2)));
	σ_b = σ_y * sqrt(x_2 / (N * x_2 - pow(x_1, 2)));


	//gnuplotによる描画
	FILE* gp = _popen("gnuplot", "w");
	assert(gp);

	//各設定
	fprintf(gp, "reset\n");
	fprintf(gp, "set key left top\n");
	fprintf(gp, "set zeroaxis\n");
	fprintf(gp, "set xrange [%lf:%lf]\n", (float)(x[N - 1] - abs(x[0] - x[N - 1]) / N), (float)(x[0] + abs(x[0] - x[N - 1]) / N));
	fprintf(gp, "set yrange [%lf:%lf]\n", (float)(y[N - 1] - abs(y[0] - y[N - 1]) / N), (float)(y[0] + abs(y[0] - y[N - 1]) / N));
	fprintf(gp, "set lmargin 15\n");
	fprintf(gp, "set rmargin 5\n");
	fprintf(gp, "set tmargin 2\n");
	fprintf(gp, "set bmargin 5\n");
	fprintf(gp, "set grid\n");

	//データプロット、最適推定値グラフ表示
	fprintf(gp, "plot '-' pt 7 ps 0.7 linetype rgbcolor '#FF0000' title '測定値', %lf * x + %lf linetype rgbcolor '#000000' title '{/Times-New-Roman:Italic=10 r}{/Times-New-Roma=10 (}{/Times-New-Roman:Italic=10 t}{/Times-New-Roma=10 ) = (00.9±0.002)}{/Times-New-Roman:Italic=10 t }{/Times-New-Roma=10 + (500±0.1)}\n", (float)a, (float)b);
	for (int i = 0; i < N; i++)
	{
		fprintf(gp, "%lf, %lf\n", x[i], y[i]);
	}
	fprintf(gp, "e\n");
	fflush(gp);


	//情報表示
	std::cout << "y = (" << a << "±" << σ_a << ")x + (" << b << "±" << σ_b << ")" << std::endl << std::endl;
	std::cout << "y = (a±σ_a)x + (b±σ_b)" << std::endl << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "σ_a = " << σ_a << std::endl;
	std::cout << "σ_b = " << σ_b << std::endl << std::endl;
	std::cout << "σ_y = " << σ_y << std::endl << std::endl;
	std::cout << "finish" << std::endl;


	while (1) {
		if ('\r' == _getch()) break;
	}
	_pclose(gp);
	return 0;
}
