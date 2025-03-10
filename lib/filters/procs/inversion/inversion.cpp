//
// Created by anton on 3/11/25.
//

#include "inversion.hpp"
void InversionFilter::apply(QImage& image) {
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            auto color = image.pixelColor(x, y);
            image.setPixelColor(x,y,QColor(255-color.red(),255 - color.green(),255 - color.blue()));
        }
    }
}