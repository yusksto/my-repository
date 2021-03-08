#include <cstdio>
#include <cassert>

int main() {
    FILE* gp = _popen("gnuplot", "w");
    assert(gp);

    fprintf(gp, "set terminal gif animate optimize delay 10 size 400,400\n");
    fprintf(gp, "set output 'tmp.gif'\n");

    fprintf(gp, "set nokey\n");
    fprintf(gp, "set size square\n");
    fprintf(gp, "set xr [0:15]\n");
    fprintf(gp, "set yr [0:15]\n");

    for (int j = 0; j < 10; j++) {

        fprintf(gp, "plot '-' pt 5 ps 2, '-' pt 5 ps 2\n");
        fprintf(gp, "%d, %d\n", 1 + j, 1 + j);
        fprintf(gp, "%d, %d\n", 2 + j, 2 + j);
        fprintf(gp, "e\n");
        fprintf(gp, "%d, %d\n", 1 + j, 2 + j);
        fprintf(gp, "%d, %d\n", 2 + j, 1 + j);
        fprintf(gp, "%d, %d\n", 2 + j, 3 + j);
        fprintf(gp, "e\n");
    }
    _pclose(gp);

    return 0;
}