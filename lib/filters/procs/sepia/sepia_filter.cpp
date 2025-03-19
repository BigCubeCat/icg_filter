#include "sepia_filter.hpp"

void SepiaFilter::apply([[maybe_unused]] QImage& image) {
    qDebug() << m_percent;
    for (int y = 0; y < image.height(); ++y) {
        QRgb* row = reinterpret_cast<QRgb*>(image.scanLine(y));

        for (int x = 0; x < image.width(); ++x) {
            QRgb& pixel = row[x];

            // Извлекаем цветовые компоненты
            int r = qRed(pixel);
            int g = qGreen(pixel);
            int b = qBlue(pixel);
            int a = qAlpha(pixel);
            int sepia_r = (393 * r + 769 * g + 189 * b) / 1000;
            int sepia_g = (349 * r + 686 * g + 168 * b) / 1000;
            int sepia_b = (272 * r + 534 * g + 131 * b) / 1000;
            sepia_r = std::min(sepia_r, 255);
            sepia_g = std::min(sepia_g, 255);
            sepia_b = std::min(sepia_b, 255);
            r = (r * (100 - m_percent) + sepia_r * m_percent) / 100;
            g = (g * (100 - m_percent) + sepia_g * m_percent) / 100;
            b = (b * (100 - m_percent) + sepia_b * m_percent) / 100;

            // Гарантируем допустимые значения цветов
            r = std::clamp(r, 0, 255);
            g = std::clamp(g, 0, 255);
            b = std::clamp(b, 0, 255);

            // Обновляем пиксель с сохранением альфа-канала
            pixel = qRgba(r, g, b, a);
        }
    }

    emit done();
}
