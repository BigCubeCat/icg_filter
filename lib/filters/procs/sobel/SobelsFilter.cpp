//
// Created by anton on 3/18/25.
//

#include "SobelsFilter.hpp"

#include <QVariant>

#include "Convolution.hpp"
SobelsFilter::SobelsFilter() {
    first_step.push_back(QVector<int>({-1, 0, 1}));
    first_step.push_back(QVector<int>({-2, 0, 2}));
    first_step.push_back(QVector<int>({-1, 0, 1}));

    second_step.push_back(QVector<int>({-1, -2, -1}));
    second_step.push_back(QVector<int>({0, 0, 0}));
    second_step.push_back(QVector<int>({1, 2, 1}));
}
void SobelsFilter::apply(QImage& image) {
    QImage first = image.copy();
    QImage second = image.copy();


    Convolution::convolution(first, first_step, 1, true, true);
    Convolution::convolution(second, second_step, 1, true, true);
    for (int y = 0; y < first.height(); ++y) {
        for (int x = 0; x < first.width(); x++) {
            QColor color = first.pixelColor(x, y);
            QColor color2 = second.pixelColor(x, y);
            uchar r = (color.red() + color2.red() <= m_threshold) ? 0 : 255;
            uchar g = (color.green() + color2.green() <= m_threshold) ? 0 : 255;
            uchar b = (color.blue() + color2.blue() <= m_threshold) ? 0 : 255;

            image.setPixelColor(x, y, QColor(r,g,b));
        }
    }
}
void SobelsFilter::setThreshold(const QVariant& threshold) {
    m_threshold = threshold.toInt();
}