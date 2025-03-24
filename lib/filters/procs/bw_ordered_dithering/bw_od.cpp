#include "bw_od.hpp"
#include <array>
#include <cmath>

const int kN = 16;

namespace {
double bayer(int i, int j, int n) {
    unsigned char b = ~((i % n) ^ (j % n));
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return static_cast<double>(b) / (n * n);
}
};  // namespace

void BWOrderedDitheringFilter::apply(QImage& image) {
    int step = 255 / (m_cnt_quants - 1);

    const int height = image.height();
    const int width = image.width();

    std::array<std::array<double, kN>, kN> bayer_matrix{};
    for (int i = 0; i < kN; ++i) {
        for (int j = 0; j < kN; ++j) {
            bayer_matrix[i][j] = step * bayer(i, j, kN);
        }
    }
#pragma omp parallel for collapse(2)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto color = image.pixelColor(x, y);
            double pixel = (0.299 * color.red()) + (0.587 * color.green()) +
                           (0.114 * color.black()) +
                           bayer_matrix[y % kN][x % kN];
            pixel = std::round(pixel / step) * step;
            image.setPixelColor(x, y, qRgb(pixel, pixel, pixel));
        }
    }
}
