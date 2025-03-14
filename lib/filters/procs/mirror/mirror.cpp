#include "mirror.hpp"

void MirrorFilter::apply([[maybe_unused]] QImage& image) {
    const int width = image.width();
    const int height = image.height();
    QImage new_image = QImage(width, height, QImage::Format_ARGB32);
    if (m_value == 1) {
        for (int row = 0; row <= height / 2; ++row) {
            for (int col = 0; col < width; ++col) {
                new_image.setPixelColor(col, row,
                                        image.pixelColor(col, height - row));
                new_image.setPixelColor(col, height - row,
                                        image.pixelColor(col, row));
            }
        }
    } else {
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col <= width / 2; ++col) {
                new_image.setPixelColor(col, row,
                                        image.pixelColor(width - col - 1, row));
                new_image.setPixelColor(width - col - 1, row,
                                        image.pixelColor(col, row));
            }
        }
    }
    image = new_image;
}
