#include "alpha.hpp"
#include <qpainter.h>

void AlphaFilter::apply([[maybe_unused]] QImage& image) {
    QImage second = QImage(m_imagePath);
    qDebug() << "variant = " << m_variant;
    if (m_variant == 0) {
        second = second.scaled(image.size(), Qt::IgnoreAspectRatio);
    }
    // Конвертация в ARGB32, если нужно
    if (image.format() != QImage::Format_ARGB32) {
        image = image.convertToFormat(QImage::Format_ARGB32);
    }

    if (second.format() != QImage::Format_ARGB32) {
        second = second.convertToFormat(QImage::Format_ARGB32);
    }

    QPainter painter(&image);
    painter.setOpacity(m_percent / 100.0F);

    if (m_variant == 1) {  // Tiling
        apply_tiling(image, second, &painter);
    } else {
        apply(image, second, QPoint(0, 0), &painter);
    }
    painter.end();
    emit done();
}

void AlphaFilter::apply_tiling([[maybe_unused]] QImage& image,
                               const QImage& second, QPainter* painter_ptr) {
    const auto tile_width = second.width();
    const auto tile_height = second.height();
    const auto count_rows = (image.height() / second.height()) +
                            ((image.height() % second.height() == 0) ? 0 : 1);
    const auto count_cols = (image.width() / second.width()) +
                            ((image.width() % second.width() == 0) ? 0 : 1);
    for (int row = 0; row < count_rows; ++row) {
        for (int col = 0; col < count_cols; ++col) {
            painter_ptr->drawImage(col * tile_width, row * tile_height, second);
        }
    }
}

void AlphaFilter::apply([[maybe_unused]] QImage& image, const QImage& second,
                        const QPoint& start, QPainter* painter_ptr) {
    painter_ptr->drawImage(start, second);
}
