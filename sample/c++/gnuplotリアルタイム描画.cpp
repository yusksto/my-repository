#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <cassert>
#include <iostream>

int main()
{
	const float dx = 0.2f;
	const float dy = 0.2f;
	const int xrange = 10;//+-
	const int yrange = 10;//+-



	FILE* gp = _popen("gnuplot", "w");
	assert(gp);

	fprintf(gp, "unset key\n");
	fprintf(gp, "set xr [%d:%d]\n", (int)(-xrange * 1.5f), (int)(xrange * 1.5f));
	fprintf(gp, "set yr [%d:%d]\n", (int)(-yrange * 1.5f), (int)(yrange * 1.5f));
	fprintf(gp, "set zr [%d:%d]\n", -2, 2);

	for (float i = 0; i < 100; i += 0.2f)
	{

		fprintf(gp, "splot \"-\" with lines \n");
		for (float x = -xrange; x < xrange; x += dx)
		{
			for (float y = -yrange; y < yrange; y += dy)
			{
				fprintf(gp, "%lf, %lf, %lf\n", x, y, (float)(sin(x + i) * sin(y + i)));

			}
		}
		fprintf(gp, "e\n");
		fflush(gp);
	}

	_pclose(gp);
	return 0;
}
