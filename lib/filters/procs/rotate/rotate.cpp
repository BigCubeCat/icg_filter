#include "rotate.hpp"
#include <QPainter>

#include <algorithm>

void RotateFilter::apply([[maybe_unused]] QImage& image) {
    int normalized_angle = m_angle % 360;
    if (normalized_angle < 0) {
        normalized_angle += 360;
    }

    // Для углов кратных 90 градусов используем стандартный поворот
    if (normalized_angle % 90 == 0) {
        QTransform transform;
        transform.rotate(normalized_angle);
        image = image.transformed(transform, Qt::FastTransformation);
        return;
    }

    // Для произвольных углов вычисляем новый размер и поворачиваем с белым фоном
    const int w = image.width();
    const int h = image.height();
    const double cx = w / 2.0;
    const double cy = h / 2.0;
    const double radians =
        qDegreesToRadians(static_cast<double>(normalized_angle));
    const double cos_a = std::cos(radians);
    const double sin_a = std::sin(radians);

    // Поворачиваем углы изображения для определения нового размера
    QPointF corners[4] = {QPointF(0, 0), QPointF(w, 0), QPointF(w, h),
                          QPointF(0, h)};
    double min_x = 0;
    double max_x = 0;
    double min_y = 0;
    double max_y = 0;

    for (int i = 0; i < 4; ++i) {
        const double x = corners[i].x() - cx;
        const double y = corners[i].y() - cy;

        const double rotated_x = (x * cos_a) - (y * sin_a) + cx;
        const double rotated_y = (x * sin_a) + (y * cos_a) + cy;

        if (i == 0) {
            min_x = max_x = rotated_x;
            min_y = max_y = rotated_y;
        } else {
            min_x = std::min(rotated_x, min_x);
            max_x = std::max(rotated_x, max_x);
            min_y = std::min(rotated_y, min_y);
            max_y = std::max(rotated_y, max_y);
        }
    }

    // Создаем новое изображение с белым фоном
    const int new_width = static_cast<int>(std::ceil(max_x - min_x));
    const int new_height = static_cast<int>(std::ceil(max_y - min_y));
    QImage new_image(new_width, new_height, image.format());
    new_image.fill(Qt::white);

    // Рисуем повернутое изображение
    QPainter painter(&new_image);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    // Вычисляем смещение для центрирования
    painter.translate(new_width / 2.0, new_height / 2.0);
    painter.rotate(normalized_angle);
    painter.translate(-cx, -cy);

    painter.drawImage(0, 0, image);
    painter.end();

    image = new_image;

    emit done();
}
