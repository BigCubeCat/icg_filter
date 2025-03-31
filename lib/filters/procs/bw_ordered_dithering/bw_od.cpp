#include "bw_od.hpp"
#include <array>
#include <cmath>

#include "dithering_utils.hpp"

const int kN = 16;

void BWOrderedDitheringFilter::apply(QImage& image) {
    if (image.format() != QImage::Format_RGB32) {
        image = image.convertToFormat(QImage::Format_RGB32);
    }
    QImage out(image.size(), QImage::Format_RGB32);

    // Матрица Байера 4x4
    const static int kBayerMatrix[4][4] = {
        {15, 7, 13, 5}, {3, 11, 1, 9}, {12, 4, 14, 6}, {0, 8, 2, 10}};
    const int matrix_size = 4;

    const int height = image.height();
    const int width = image.width();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Получаем интенсивность пикселя (0-255)
            QRgb pixel = image.pixel(x, y);
            int intensity = qGray(pixel);

            // Определяем позицию в матрице Байера
            int mx = x % matrix_size;
            int my = y % matrix_size;

            // Рассчитываем пороговое значение
            float threshold = (kBayerMatrix[my][mx] + 0.5F) /
                              (matrix_size * matrix_size) * 255.0F;
            auto value = (intensity >= threshold) ? 255 : 0;
            // Применяем дизеринг
            out.setPixel(x, y, qRgb(value, value, value));
        }
    }
    image = out;
}
