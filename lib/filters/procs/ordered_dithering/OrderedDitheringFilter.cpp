//
// Created by anton on 3/19/25.
//

#include "OrderedDitheringFilter.hpp"

double bayer(int i, int j, int n) {
    unsigned char b = ~((i % n) ^ (j % n));
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return static_cast<double>(b) / (n * n);
}

void OrderedDitheringFilter::apply(QImage& image) {
    double disp =
        255.0 * 3.0 /
        std::log2(m_cnt_red_quants * m_cnt_green_quants * m_cnt_blue_quants);

    int n = 16;

    int r_step = 255 / (m_cnt_red_quants - 1);
    int g_step = 255 / (m_cnt_green_quants - 1);
    int b_step = 255 / (m_cnt_blue_quants - 1);

    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            QColor color = image.pixelColor(x, y);
            double r = color.red() + r_step * (bayer(y, x, n) -0.5);
            double g = color.green() + g_step * (bayer(y, x, n) -0.5);
            double b = color.blue() + b_step * (bayer(y, x, n) -0.5);
            int new_red = std::round(r / r_step) * r_step;
            int new_green = std::round(g / g_step) * g_step;
            int new_blue = std::round(b / b_step) * b_step;
            image.setPixelColor(x, y, qRgb(new_red, new_green, new_blue));
        }
    }
}