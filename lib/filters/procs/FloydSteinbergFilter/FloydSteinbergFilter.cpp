#include "FloydSteinbergFilter.hpp"

void FloydSteinbergFilter::apply(QImage& image) {
    const int width = image.width();
    const int height = image.height();
    int r_step = 255 / (m_cnt_red_quants - 1);
    int g_step = 255 / (m_cnt_green_quants - 1);
    int b_step = 255 / (m_cnt_blue_quants - 1);

    auto* errors = new std::vector<std::vector<double>>[3];
    for (int i = 0; i < 3; i++) {
        errors[i].resize(image.height());
        for (int row = 0; row < image.height(); row++) {
            errors[i][row].resize(image.width(), 0.0);
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            QColor color = image.pixelColor(x, y);
            int new_red =
                std::round(static_cast<double>(color.red() + errors[0][y][x]) /
                           r_step) *
                r_step;
            int new_green = std::round(static_cast<double>(color.green() +
                                                           errors[1][y][x]) /
                                       g_step) *
                            g_step;
            int new_blue =
                std::round(static_cast<double>(color.blue() + errors[2][y][x]) /
                           b_step) *
                b_step;

            double new_errors[3];
            new_errors[0] = color.red() + errors[0][y][x] - new_red;
            new_errors[1] = color.green() + errors[1][y][x] - new_green;
            new_errors[2] = color.blue() + errors[2][y][x] - new_blue;

            for (int i = 0; i < 3; i++) {
                if (x + 1 < image.width()) {
                    errors[i][y][x + 1] += new_errors[i] * 7 / 16;
                }
                if (y + 1 < image.height()) {
                    errors[i][y + 1][x] += new_errors[i] * 5 / 16;
                    if (x - 1 >= 0) {
                        errors[i][y + 1][x - 1] += new_errors[i] * 3 / 16;
                    }
                    if (x + 1 < image.width()) {
                        errors[i][y + 1][x + 1] += new_errors[i] * 1 / 16;
                    }
                }
            }

            image.setPixel(x, y, qRgb(new_red, new_green, new_blue));
        }
    }
    delete[] errors;
}
