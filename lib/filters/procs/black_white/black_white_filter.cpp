#include "black_white_filter.hpp"

void BlackWhiteFilter::apply(QImage& image) {
    const int height = image.height();
    const int width = image.width();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto color = image.pixelColor(x, y);
            int grey_lvl = (0.299 * color.red()) + (0.587 * color.green()) +
                           (0.114 * color.black());
            image.setPixelColor(x, y, QColor(grey_lvl, grey_lvl, grey_lvl));
        }
    }
}
