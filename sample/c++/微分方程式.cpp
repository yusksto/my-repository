//　y = e^x　を表す微分方程式　dy/dx = y + c (cは定数)　をオイラー法を用いて解く　//

#include <iostream>
#include <fstream>

const double y_0 = 1;
const double x_0 = 0;
const double x_1 = 100;
const double dx = 0.1;

int main()
{
    std::ofstream ofs;
    ofs.open("data.txt", std::ios::out);
    for (double x = x_0,y = y_0; x <= x_1; x += dx,y = y * (1 + dx)) {
        ofs << x << " " << y << std::endl;
    }
    ofs.close();
    return 0;
}
