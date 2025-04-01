#include "OrderedDitheringFilter.hpp"

#include <iostream>

#include "dithering_utils.hpp"

static uint get_nearest_power(uint val) {
    uint shift = 0;
    uint off = 0;
    while (val >> 1 > 0) {
        if (1 & val)
            shift = 1;
        ++off;
        val >>= 1;
    }
    if ((off + shift) % 2 != 0) {
        ++off;
    }
    return val << ((shift + off) / 2);
}

inline double bayer(int i, int j, int n) {
    unsigned char p = ((i % n) ^ (j % n));
    unsigned char b = (p & 0x01) | ((i << 1) & 0x02) | ((p << 1) & 0x04) |
                      ((i << 2) & 0x08) | ((p << 2) & 0x10) |
                      ((i << 3) & 0x20) | ((p << 3) & 0x40) | ((i << 4) & 0x80);
    switch (n) {
        case 2: {
            b = (b & 0x02) >> 1 | (b & 0x01) << 1;
            return static_cast<double>(b)/(n * n);
        }
        case 4: {
            b = (b & 0x0C) >> 2 | (b & 0x03) << 2;
            b = (b & 0x0A) >> 1 | (b & 0x05) << 1;
            return static_cast<double>(b)/(n * n);
        }
        case 8: {
            b = (b & 0x38) >> 3 | (b & 0x07) << 3;
            b = (b & 0x24) >> 2 | (b & 0x09) << 2 | (b & 0x12);
            return static_cast<double>(b)/(n * n);
        }
        case 16: {
            b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
            b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
            b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
            return static_cast<double>(b)/(n * n);
        }
        default:
            qDebug() << "unexpected size of matrix! ERROR";
            return b;
    }
}

void OrderedDitheringFilter::apply(QImage& image) {
    auto out = image;
    const auto red_kn = get_nearest_power(256 / m_cnt_red_quants);
    const auto green_kn = get_nearest_power(256 / m_cnt_green_quants);
    const auto blue_kn = get_nearest_power(256 / m_cnt_blue_quants);

    const int height = image.height();
    const int width = image.width();

    const int r_step = 256 / (m_cnt_red_quants - 1);
    const int g_step = 256 / (m_cnt_green_quants - 1);
    const int b_step = 256 / (m_cnt_blue_quants - 1);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            QColor color = out.pixelColor(x, y);
            const double r =
                color.red() + (r_step * (bayer(y, x, red_kn) - 0.5));
            //qDebug() << bayer(y, x, red_kn);
            const double g =
                color.green() + (g_step * (bayer(y, x, green_kn) - 0.5));
            //qDebug() << bayer(y, x, green_kn);
            const double b =
                color.blue() + (b_step * (bayer(y, x, blue_kn) - 0.5));
            //qDebug() << bayer(y, x, blue_kn);
            const int new_red = std::max(
                std::min(static_cast<int>(std::round(r / r_step) * r_step),
                         255),
                0);
            const int new_green = std::max(
                std::min(static_cast<int>(std::round(g / g_step) * g_step),
                         255),
                0);
            const int new_blue = std::max(
                std::min(static_cast<int>(std::round(b / b_step) * b_step),
                         255),
                0);
            out.setPixelColor(x, y, qRgb(new_red, new_green, new_blue));
        }
    }
    image = out;
}
