#include "floyd.hpp"

void BlackWhiteFloydSteinbergFilter::apply(QImage& image) {
    const int height = image.height();
    const int width = image.width();

    std::array<std::vector<std::vector<double>>, 3> errors{};
    for (int i = 0; i < 3; i++) {
        errors[i].resize(height + 1);
        for (int j = 0; j < height + 1; j++) {
            errors[i][j].resize(width + 1, 0.0);
        }
    }
    uint uint_width = static_cast<uint>(width);
    QImage out = image.convertToFormat(QImage::Format_ARGB32);
    for (int y = 0; y < height; ++y) {
        QRgb* scan_line = reinterpret_cast<QRgb*>(out.scanLine(y));
        for (uint x = 0; x < uint_width; ++x) {
            QRgb pixel = scan_line[x];
            int r = qRed(pixel);
            int g = qGreen(pixel);
            int b = qBlue(pixel);
            int new_red = std::round(static_cast<double>(r + errors[0][y][x]) /
                                     m_step_red) *
                          m_step_red;
            int new_green =
                std::round(static_cast<double>(g + errors[1][y][x]) /
                           m_step_green) *
                m_step_green;
            int new_blue = std::round(static_cast<double>(b + errors[2][y][x]) /
                                      m_step_blue) *
                           m_step_blue;
            std::array<double, 3> new_errors{r + errors[0][y][x] - new_red,
                                             g + errors[1][y][x] - new_green,
                                             b + errors[2][y][x] - new_blue};
            for (int i = 0; i < 3; i++) {
                errors[i][y][x + 1] += new_errors[i] * 7 / 16;
                errors[i][y + 1][x] += new_errors[i] * 5 / 16;
                errors[i][y + 1][x + 1] += new_errors[i] * 1 / 16;
                errors[i][y + 1][std::min(x - 1, uint_width)] +=
                    new_errors[i] * 3 / 16;
            }
            scan_line[x] = qRgb(new_red, new_green, new_blue);
        }
    }
    image = out;
}
