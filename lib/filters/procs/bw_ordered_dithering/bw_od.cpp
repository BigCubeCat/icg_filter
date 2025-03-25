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

#define stepify(x, step) static_cast<uchar>(std::round((x) / (step)) * (step));

void BWOrderedDitheringFilter::apply(QImage& image) {
    const int step = 255 / (m_cnt_quants - 1);

    const int height = image.height();
    const int width = image.width();

    std::array<std::array<double, kN>, kN> bayer_matrix{};
    for (int i = 0; i < kN; ++i) {
        for (int j = 0; j < kN; ++j) {
            bayer_matrix[i][j] = step * bayer(i, j, kN);
        }
    }
    auto out = QImage(width, height, QImage::Format_Grayscale8);

    image.convertTo(QImage::Format_Grayscale8);

    // ускорение ровно в 8 раз
#pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        const uchar* inpt_line = image.constScanLine(y);
        uchar* otp_line = out.scanLine(y);
        for (int x = 0; x < width; ++x) {
            otp_line[x] =
                stepify(inpt_line[x] + bayer_matrix[y % kN][x % kN], step);
        }
    }
    image = out;
}
