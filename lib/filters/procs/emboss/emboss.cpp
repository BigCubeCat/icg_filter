#include "emboss.hpp"

#include <cmath>

void EmbossFilter::apply([[maybe_unused]] QImage& image) {
    image = image.convertToFormat(QImage::Format_RGB32);
    QImage result(image.size(), image.format());
    const QColor color = QColor(m_color);
    result.fill(color);

    const int width = image.width();
    const int height = image.height();

    const int l_border = -std::min(m_offset_x, 0);
    const int t_border = -std::min(m_offset_y, 0);

    const int r_border = width - std::max(m_offset_x, 0);
    const int b_border = height - std::max(m_offset_y, 0);

#pragma omp parallel for
    for (int y = t_border; y < b_border; ++y) {
        for (int x = l_border; x < r_border; ++x) {
            QColor current = image.pixelColor(x, y);
            QColor neighbor = image.pixelColor(x + m_offset_x, y + m_offset_y);
            const int red_diff = current.red() - neighbor.red();
            const int green_diff = current.green() - neighbor.green();
            const int blue_diff = current.blue() - neighbor.blue();
            const int diff =
                qBound(0, ((red_diff + green_diff + blue_diff) / 3) + 128, 255);
            result.setPixel(
                x, y,
                qRgb(diff * color.red() / 255, diff * color.green() / 255,
                     diff * color.blue() / 255));
        }
    }
    image = result;
    qDebug() << "done emboss";

    emit done();
}
