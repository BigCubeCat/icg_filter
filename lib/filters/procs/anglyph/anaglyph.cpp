//
// Created by anton on 3/16/25.
//

#include "anaglyph.hpp"
void AnaglyphFilter::apply(QImage& image) {
    QImage second = image;
    if (m_imagePath.length() > 0) {
        second = QImage(m_imagePath);
    }

    QImage result = QImage(std::max(second.width(), image.width()) - m_offset,
               std::max(image.height(), second.height()), QImage::Format_RGB32);


    auto color = QColor{Qt::black};
    auto second_color = QColor{Qt::black};
    for (int y = 0; y < result.height(); y++) {
        for (int x = 0; x < result.width(); x++) {
            if (x + m_offset < image.width() && y < image.height()) {
                color = image.pixelColor(x + m_offset, y);
            } else {
                color = QColor(Qt::black);
            }
            if (x < second.width() - m_offset && y < second.height()) {
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