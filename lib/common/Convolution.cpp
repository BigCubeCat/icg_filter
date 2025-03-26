#include "Convolution.hpp"

#include <iostream>

void Convolution::convolution(QImage& image,
                              const QVector<QVector<int>>& kernel,
                              const int& denum, bool absolute,
                              bool continousBorder) {
    const int ks = kernel.size();
    const int st = -ks / 2;
    const int fn = (ks - 1) / 2;
    const int iw = image.width();
    const int ih = image.height();

    const uchar* src = image.bits();
    auto dst = new short[ih * iw * 3];  //rgb
    auto res = new uchar[ih * iw * 4];

    for (int ki = st; ki <= fn; ++ki) {
        for (int kj = st; kj <= fn; ++kj) {

            const int k_coef = kernel[ki - st][kj - st];
            for (int i = 0; i < ih; ++i) {
                for (int j = 0; j < iw; ++j) {
                    uchar r = 0;
                    uchar g = 0;
                    uchar b = 0;

                    if (i + ki >= 0 && j + kj >= 0 && i + ki < ih &&
                        j + kj < iw) {
                        int idx = 4 * ((i + ki) * iw + j + kj);
                        r = src[idx + 2];
                        g = src[idx + 1];
                        b = src[idx];
                    } else if (continousBorder) {
                        int idx = 4 * (i * iw + j);
                        r = src[idx + 2];
                        g = src[idx + 1];
                        b = src[idx];
                    }
                    int idx = 3 * (i * iw + j);
                    if (ki == st && kj == st) {
                        dst[idx] = r * k_coef;
                        dst[idx + 1] = g * k_coef;
                        dst[idx + 2] = b * k_coef;
                    } else {
                        dst[idx] += r * k_coef;
                        dst[idx + 1] += g * k_coef;
                        dst[idx + 2] += b * k_coef;
                    }
                    int res_idx = 4 * (i * iw + j);
                    if ((ki == fn) && (kj == fn) && absolute) {
                        res[res_idx] =
                            std::min(abs(dst[idx + 2] / denum), 255);  // blue
                        res[res_idx + 1] =
                            std::min(abs(dst[idx + 1] / denum), 255);  //green
                        res[res_idx + 2] =
                            std::min(abs(dst[idx] / denum), 255);  // red
                        res[res_idx + 3] = 255;                    //alpha
                    } else {
                        res[res_idx] = std::max(
                            std::min(dst[idx + 2] / denum, 255), 0);  // blue
                        res[res_idx + 1] = std::max(
                            std::min(dst[idx + 1] / denum, 255), 0);  //green
                        res[res_idx + 2] = std::max(
                            std::min(dst[idx] / denum, 255), 0);  // red
                        res[res_idx + 3] = 255;                   //alpha
                    }
                }
            }
        }
    }
    image = QImage(res, iw, ih, QImage::Format_RGB32);
    delete[] dst;
}