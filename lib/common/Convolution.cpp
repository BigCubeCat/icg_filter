#include "Convolution.hpp"

#include <iostream>

void Convolution::convolution(QImage& image,
                              const QVector<QVector<int>>& kernel, const int &denum) {
    const int ks = kernel.size();
    const int st = -ks/2;
    const int fn = ks/2;
    const int iw = image.width();
    const int ih = image.height();

    const uchar *src = image.bits();
    auto *dst = new short[ih * iw * 3]; //rgb
    auto *res = new uchar[ih * iw * 4];


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
                        r = src[(4 * ((i + ki) * iw + j + kj)) + 2];
                        g = src[(4 * ((i + ki) * iw + j + kj)) + 1];
                        b = src[(4 * ((i + ki) * iw + j + kj)) ];
                    }
                    if (ki == st && kj == st) {
                        dst[(3 * (i * iw + j))] = r * k_coef;
                        dst[(3 * (i * iw + j)) + 1] = g * k_coef;
                        dst[(3 * (i * iw + j)) + 2] = b * k_coef;
                    } else {
                        dst[(3 * (i * iw + j))] += r * k_coef;
                        dst[(3 * (i * iw + j)) + 1] += g * k_coef;
                        dst[(3 * (i * iw + j)) + 2] += b * k_coef;
                    }


                    if (ki == fn && kj == fn) {
                        res[4 * (i * iw + j)] = dst[(3 * (i * iw + j)) + 2] / denum; // blue
                        res[(4 * (i * iw + j)) + 1] = dst[(3 * (i * iw + j)) + 1] / denum; //green
                        res[(4 * (i * iw + j)) + 2] = dst[3 * (i * iw + j)] / denum;// red
                        res[(4 * (i * iw + j)) + 3] = src[4 * ((i + ki) * iw + j)]; //alpha
                    }
                }
            }
        }
    }

    image = QImage(res, iw, ih, QImage::Format_RGB32);
    delete[] dst;
    delete[] res;
}