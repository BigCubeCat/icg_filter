#include "bw_od.hpp"
#include <qrgba64.h>
#include <cmath>

#include <QColor>
#include <QImage>
#include <QVector>

namespace {
int calculate_matrix_size(int red, int green, int blue) {
    const QVector<int> sizes = {2, 4, 8, 16};
    double max_step = std::max({256.0 / red, 256.0 / green, 256.0 / blue});

    for (int s : sizes) {
        if (max_step <= s * s)
            return s;
    }
    return 16;
}
};  // namespace

QVector<QVector<double>> BWOrderedDitheringFilter::generate_threshold_matrix(
    int size) {
    if (size == 2) {
        return m_base_kernel;
    }

    auto sub_matrix = generate_threshold_matrix(size / 2);
    int sub_size = sub_matrix.size();
    QVector<QVector<double>> matrix(size, QVector<double>(size));

    for (int y = 0; y < sub_size; ++y) {
        for (int x = 0; x < sub_size; ++x) {
            matrix[y][x] = 4 * sub_matrix[y][x];
        }
    }

    for (int y = sub_size; y < size; ++y) {
        for (int x = 0; x < sub_size; ++x) {
            matrix[y][x] = 4 * sub_matrix[y % sub_size][x] + 2;
        }
    }

    for (int y = 0; y < sub_size; ++y) {
        for (int x = sub_size; x < size; ++x) {
            matrix[y][x] = 4 * sub_matrix[y][x % sub_size] + 3;
        }
    }


    for (int y = sub_size; y < size; ++y) {
        for (int x = sub_size; x < size; ++x) {
            matrix[y][x] = 4 * sub_matrix[y % sub_size][x % sub_size] + 1;
        }
    }

    return matrix;
}

void BWOrderedDitheringFilter::normalize_matrix() {
    double factor = 1.0 / (m_matrix_size * m_matrix_size);
    for (auto& row : m_threshold_map) {
        for (auto& val : row) {
            val = (val + 1) * factor;
        }
    }
}

void BWOrderedDitheringFilter::apply(QImage& image) {
    qDebug() << "Egor's dithering\n";
    if (image.format() != QImage::Format_RGB32) {
        image = image.convertToFormat(QImage::Format_RGB32);
    }

    QImage out = image.convertToFormat(QImage::Format_ARGB32);
    const int width = image.width();
    const int height = image.height();
    m_matrix_size = calculate_matrix_size(m_cnt_red_quants, m_cnt_green_quants,
                                          m_cnt_blue_quants);
    m_threshold_map = generate_threshold_matrix(m_matrix_size);
    normalize_matrix();
#pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        QRgb* scan_line = reinterpret_cast<QRgb*>(out.scanLine(y));
        for (int x = 0; x < width; ++x) {
            QRgb pixel = scan_line[x];

            int r = qRed(pixel);
            int g = qGreen(pixel);
            int b = qBlue(pixel);

            const double threshold =
                m_threshold_map[y % m_matrix_size][x % m_matrix_size];

            r = std::round((r + m_step_red * (threshold - 0.5F)) / m_step_red) *
                m_step_red;
            g = std::round((g + m_step_green * (threshold - 0.5F)) /
                           m_step_green) *
                m_step_green;
            b = std::round((b + m_step_blue * (threshold - 0.5F)) /
                           m_step_blue) *
                m_step_blue;

            scan_line[x] =
                qRgb(qBound(0, r, 255), qBound(0, g, 255), qBound(0, b, 255));
        }
    }
    image = out;
}
