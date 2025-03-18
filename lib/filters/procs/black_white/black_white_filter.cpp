//
// Created by anton on 3/11/25.
//

#include "black_white_filter.hpp"

void BlackWhiteFilter::apply(QImage& image) {
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            auto color = image.pixelColor(x, y);
            int grey_lvl = 0.299 * color.red() + 0.587 * color.green() +
                           0.114 * color.black();
            image.setPixelColor(x, y, QColor(grey_lvl, grey_lvl, grey_lvl));
        }
    }
}