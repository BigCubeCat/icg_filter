#include "floyd.hpp"

#include "dithering_utils.hpp"

void BlackWhiteFloydSteinbergFilter::apply(QImage& image) {
    const int step = 255 / (m_cnt_quants - 1);
    const int height = image.height();
    const int width = image.width();

    auto errors = std::vector<std::vector<double>>(height + 1);
    for (int row = 0; row < height + 1; row++) {
        errors[row].resize(width + 1, 0.0);
    }
    // ускорение в 2 раза
    auto out = QImage(width, height, QImage::Format_Grayscale8);
    image.convertTo(QImage::Format_Grayscale8);
    const auto t = -(width + 1);
    for (int y = 0; y < height; ++y) {
        const uchar* inpt_line = image.constScanLine(y);
        uchar* otp_line = out.scanLine(y);
        for (int x = 0; x < width; ++x) {
            otp_line[x] = stepify(inpt_line[x] + errors[y][x], step);
            auto new_error = inpt_line[x] + errors[y][x] - otp_line[x];
            errors[y][x + 1] += new_error * 7 / 16;
            errors[y + 1][x] += new_error * 5 / 16;
            errors[y + 1][x + 1] += new_error * 1 / 16;
            // если в границе то 0 + x - 1 иначе width + 1, неиспользуемое
            errors[y + 1][(std::min(x - 1, 0) * t) + x - 1] +=
                new_error * 3 / 16;
        }
    }
    image = out;
    //
    // for (int y = 0; y < height; y++) {
    //     for (int x = 0; x < width; x++) {
    //         QColor color = image.pixelColor(x, y);
    //         double bw_pixel = (0.299 * color.red()) + (0.587 * color.green()) +
    //                           (0.114 * color.black());
    //         double pixel = round(bw_pixel + errors[y][x], step);
    //         double new_error;
    //         new_error = bw_pixel + errors[y][x] - pixel;
    //
    //         if (x + 1 < width) {
    //             errors[y][x + 1] += new_error * 7 / 16;
    //         }
    //         if (y + 1 < height) {
    //             errors[y + 1][x] += new_error * 5 / 16;
    //             if (x - 1 >= 0) {
    //                 errors[y + 1][x - 1] += new_error * 3 / 16;
    //             }
    //             if (x + 1 < width) {
    //                 errors[y + 1][x + 1] += new_error * 1 / 16;
    //             }
    //         }
    //
    //         image.setPixel(x, y, qRgb(pixel, pixel, pixel));
    //     }
    // }
}
