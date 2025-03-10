#include "sepia_filter.hpp"

#include <cmath>

namespace {
int apply_percent(int value, double t) {
    return qMin(255, static_cast<int>(0.5 + (value * (1 - t)) + (value * t)));
};
};  // namespace

void SepiaFilter::apply([[maybe_unused]] QImage& image) {
    const int width = image.width();
    const int height = image.height();

    double t = static_cast<double>(m_percent) / 100.0F;

    qDebug() << "sepia apply";
    QImage im = QImage(width, height, QImage::Format_RGB32);

    for (int y = 0; y < height; ++y) {
        QRgb* scan_line = reinterpret_cast<QRgb*>(image.scanLine(y));
        for (int x = 0; x < width; ++x) {
            QRgb pixel = scan_line[x];
            int r = qRed(pixel);
            int g = qGreen(pixel);
            int b = qBlue(pixel);
            auto new_red = (r * 0.393) + (g * 0.769) + (b * 0.189);
            auto new_green = (r * 0.349) + (g * 0.686) + (b * 0.168);
            auto new_blue = (r * 0.272) + (g * 0.534) + (b * 0.131);
            scan_line[x] =
                qRgba(apply_percent(new_red, t), apply_percent(new_green, t),
                      apply_percent(new_blue, t), qAlpha(pixel));
            im.setPixelColor(x, y, QColor(pixel));
        }
    }

    qDebug() << "end sepia";
    image = im;

    emit done();
}
