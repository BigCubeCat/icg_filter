#include "sepia_filter.hpp"

#include <cmath>

namespace {
int gray(int r, int g, int b) {
    return (0.2126 * r) + (0.587 * g) + (0.114 * b);
}

int normalize(int value) {
    return qMin(255, value);
}
QColor sepia(QColor color, int percent) {
    auto grayscale = normalize(gray(color.red(), color.green(), color.blue()));
    return QColor(grayscale, normalize(grayscale + percent),
                  normalize(grayscale + (2 * percent)));
};
};  // namespace

void SepiaFilter::apply([[maybe_unused]] QImage& image) {
    const int width = image.width();
    const int height = image.height();

    qDebug() << m_percent;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            image.setPixelColor(x, y, sepia(image.pixelColor(x, y), m_percent));
        }
    }

    qDebug() << "end sepia";

    emit done();
}
