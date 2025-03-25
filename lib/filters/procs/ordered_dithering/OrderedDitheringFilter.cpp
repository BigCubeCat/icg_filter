#include "OrderedDitheringFilter.hpp"

#include "dithering_utils.hpp"
const int kN = 16;

void OrderedDitheringFilter::apply(QImage& image) {
    const int height = image.height();
    const int width = image.width();

    const std::array<int, 3> step = {
        255 / (m_cnt_red_quants - 1),
        255 / (m_cnt_green_quants - 1),
        255 / (m_cnt_blue_quants - 1),
    };

    std::array<std::array<std::array<double, 3>, kN>, kN> bayer_matrix{};
    for (int i = 0; i < kN; ++i) {
        for (int j = 0; j < kN; ++j) {
            bayer_matrix[i][j] = {
                step[0] * (bayer(i, j, kN) - 0.5),
                step[1] * (bayer(i, j, kN) - 0.5),
                step[2] * (bayer(i, j, kN) - 0.5),
            };
        }
    }
    auto out = QImage(width, height, QImage::Format_RGB32);
    image.convertTo(QImage::Format_RGB32);

#pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        const auto* inpt_line =
            reinterpret_cast<const QRgb*>(image.constScanLine(y));
        auto* opt_line = reinterpret_cast<QRgb*>(out.scanLine(y));
        for (int x = 0; x < image.width(); ++x) {
            const auto& rgb = inpt_line[x];
            opt_line[x] = qRgba(
                stepify(qRed(rgb) + bayer_matrix[y % kN][x % kN][0], step[0]),
                stepify(qGreen(rgb) + bayer_matrix[y % kN][x % kN][1], step[1]),
                stepify(qBlue(rgb) + bayer_matrix[y % kN][x % kN][2], step[2]),
                qAlpha(rgb));
        }
    }

    image = out;
    // -------
    // int r_step = 255 / (m_cnt_red_quants - 1);
    // int g_step = 255 / (m_cnt_green_quants - 1);
    // int b_step = 255 / (m_cnt_blue_quants - 1);
    //
    // for (int y = 0; y < height; y++) {
    //     for (int x = 0; x < width; x++) {
    //         QColor color = image.pixelColor(x, y);
    //         double r = color.red() + (r_step * (bayer(y, x, kN) - 0.5));
    //         double g = color.green() + (g_step * (bayer(y, x, kN) - 0.5));
    //         double b = color.blue() + (b_step * (bayer(y, x, kN) - 0.5));
    //         int new_red = std::round(r / r_step) * r_step;
    //         int new_green = std::round(g / g_step) * g_step;
    //         int new_blue = std::round(b / b_step) * b_step;
    //         image.setPixelColor(x, y, qRgb(new_red, new_green, new_blue));
    //     }
    // }
}
