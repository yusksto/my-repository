#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <cstddef>
#include <memory>
#include <new>
#include <random>

struct RGBA {
    unsigned char r, g, b, a; //赤, 緑, 青, 透過
    RGBA() = default;
    constexpr RGBA(const unsigned char r_, const unsigned char g_, const unsigned char b_, const unsigned char a_) :r(r_), g(g_), b(b_), a(a_) {}
};

int main() {

    constexpr std::size_t width{ 1280 }, height{ 720 }; //幅と高さ

    std::unique_ptr<RGBA[][width]> rgba(new(std::nothrow) RGBA[height][width]);
    if (!rgba) return -1;

    std::random_device rd;
    std::mt19937 mt;
    mt.seed(rd());

    std::uniform_int_distribution<> uid(0, 255);

    for (std::size_t row{}; row < height; ++row)
        for (std::size_t col{}; col < width; ++col) {
            rgba[row][col].r = uid(mt); //赤
            rgba[row][col].g = uid(mt);
            rgba[row][col].b = uid(mt);
            rgba[row][col].a = 255; //不透過
        }

    stbi_write_png("picture_2.png", static_cast<int>(width), static_cast<int>(height), static_cast<int>(sizeof(RGBA)), rgba.get(), 0);
}