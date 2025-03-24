//
// Created by anton on 3/16/25.
//

#include "anaglyph.hpp"
void AnaglyphFilter::apply(QImage& image) {
    QImage second = QImage(m_imagePath);

    QImage result = QImage(std::max(second.width(), image.width()),
               std::max(image.height(), second.height()), QImage::Format_RGB32);


    auto color = QColor{Qt::black};
    auto second_color = QColor{Qt::black};
    for (int y = 0; y < result.height(); y++) {
        for (int x = 0; x < result.width(); x++) {
            if (x < image.width() && y < image.height()) {
                color = image.pixelColor(x, y);
            } else {
                color = QColor(Qt::black);
            }
            if (x < second.width() && y < second.height()) {
                second_color = second.pixelColor(x, y);
            } else {
                second_color = QColor(Qt::black);
            }
            image.setPixelColor(x,y,QColor(color.red(),
                second_color.green(),
                second_color.blue()));
        }
    }

}