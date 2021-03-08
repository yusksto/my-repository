//
// 行列積でSIMDの効果を確認するコード．
//
#include <iostream>
#include <chrono>
//#define EIGEN_DONT_VECTORIZE
#include "Eigen/Core"

int main() {
    // 有効になっているSIMD命令を表示．
    std::cout << "Available :SIMD Instructions: " << Eigen::SimdInstructionSetsInUse() << std::endl;

    const int d = 128; // 行列の次元．
    const int n = 10000; // 繰り返し回数．

    Eigen::VectorXd t(n); // 時間格納用．
    for (int i = 0; i < n; ++i) {
        Eigen::MatrixXf m1 = Eigen::MatrixXf::Random(d, d);
        Eigen::MatrixXf m2 = Eigen::MatrixXf::Random(d, d);

        const auto start = std::chrono::system_clock::now();
        m1 *= m2;
        const auto end = std::chrono::system_clock::now();

        t[i] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
    }
    std::cout << "Average: " << t.mean() << " ms." << std::endl;
    return 0;
}