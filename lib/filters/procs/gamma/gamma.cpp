//
// Created by anton on 3/17/25.
//

#include "gamma.hpp"
#include <QVariant>
#include <algorithm>
void GammaCorrectionFiter::apply(QImage& image) {
    for (int y = 0; y < image.height(); y++) {
        for (int x = 0; x < image.width(); x++) {
            QColor color = image.pixelColor(x, y);
            int red = static_cast<int>(
                std::min(std::pow(0.0 + color.red(), m_gamma), 255.0));
            int green = static_cast<int>(
                std::min(std::pow(0.0 + color.green(), m_gamma), 255.0));
            int blue = static_cast<int>(
                std::min(std::pow(0.0 + color.blue(), m_gamma), 255.0));
            image.setPixelColor(x, y, QColor{red, green, blue});
        }
    }
}

double GammaCorrectionFiter::getGamma() const {
    return m_gamma;
}
void GammaCorrectionFiter::setGamma(const QVariant& gamma) {
    m_gamma = gamma.toDouble();
    emit gammaChanged();
}