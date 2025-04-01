//
// Created by anton on 3/19/25.
//

#include "aquarel.hpp"

#include <QVariant>

#include "Convolution.hpp"

void aquarel::apply(QImage& image) {
    QImage tmp = image.copy();
    /*
    const int ks = m_size;
    const int ks2 = ks * ks;
    const int st = -ks / 2;
    const int fn = (ks - 1) / 2;
    const int iw = image.width();
    const int ih = image.height();

    for (int y = 0; y < ih; y++) {

        MedianFinder reds{ks2};
        MedianFinder greens{ks2};
        MedianFinder blues{ks2};

        QColor ccolor = image.pixelColor(0, y);
        for (int k = 0; k < ks; k++) {
            for (int l = st; l <= fn; l++) {
                if (k <= ks / 2 || y + l < 0 || y + l >= ih) {
                    reds.push(ccolor.red());
                    greens.push(ccolor.green());
                    blues.push(ccolor.blue());
                } else {
                    QColor color = image.pixelColor(-1 + k + st, y + l);
                    reds.push(color.red());
                    greens.push(color.green());
                    blues.push(color.blue());
                }
            }
        }

        for (int x = 0; x < iw; x++) {
            ccolor = image.pixelColor(x, y);
            for (int k = st; k <= fn; k++) {
                reds.pop();
                greens.pop();
                blues.pop();

                if (x + fn >= iw || y + k < 0 || y + k >= ih) {
                    reds.push(ccolor.red());
                    greens.push(ccolor.green());
                    blues.push(ccolor.blue());
                } else {
                    QColor color = image.pixelColor(x + fn, y + k);
                    reds.push(color.red());
                    greens.push(color.green());
                    blues.push(color.blue());
                }
            }
            tmp.setPixelColor(x, y, QColor(reds.median(), greens.median(), blues.median()));
        }
    }*/

    const int ks = m_size;
    const int st = -ks / 2;
    const int fn = (ks - 1) / 2;
    const int iw = tmp.width();
    const int ih = tmp.height();
#pragma omp parallel for
    for (int y = 0; y < ih; y++) {
        auto lines = std::vector<const uchar*>(ks);
        for (int n = 0; n < ks; n++) {
            if (y + st + n < 0) {
                lines[n] = image.constScanLine(0);
            } else if (y + st + n >= ih) {
                lines[n] = image.constScanLine(ih - 1);
            } else {
                lines[n] = image.constScanLine(y + st + n);
            }
        }
        uchar* otp_line = tmp.scanLine(y);
        for (int x = 0; x < iw; x++) {
            std::vector<uchar> reds;
            std::vector<uchar> greens;
            std::vector<uchar> blues;
            for (int ki = st; ki <= fn; ++ki) {
                for (int kj = st; kj <= fn; ++kj) {
                    if (x + kj >= 0 && x + kj < iw) {
                        reds.push_back(lines[ki-st][4 * (x + kj) + 2]);
                        greens.push_back(lines[ki-st][4 * (x + kj) + 1]);
                        blues.push_back(lines[ki-st][4 * (x + kj)]);
                    } else if (x + kj < 0) {
                        reds.push_back(lines[ki-st][2]);
                        greens.push_back(lines[ki-st][1]);
                        blues.push_back(lines[ki-st][0]);
                    } else {
                        reds.push_back(lines[ki-st][4 * (iw-1) + 2]);
                        greens.push_back(lines[ki-st][4 * (iw-1) + 1]);
                        blues.push_back(lines[ki-st][4 * (iw-1)]);
                    }

                }
            }
            std::sort(reds.begin(), reds.end());
            std::sort(greens.begin(), greens.end());
            std::sort(blues.begin(), blues.end());

            otp_line[(4 * x) + 0] = blues[blues.size() / 2];
            otp_line[(4 * x) + 1] = greens[greens.size() / 2];
            otp_line[(4 * x) + 2] = reds[reds.size() / 2];
            otp_line[(4 * x) + 3] = 0xFF;
            /*tmp.setPixelColor(
                x, y,
                QColor(reds[reds.size() / 2], greens[greens.size() / 2],
                       blues[blues.size() / 2]));*/
        }
    }

    m_sharp.apply(tmp);
    image = tmp;
}
double aquarel::getSize() const {
    return m_size;
}
void aquarel::setSize(const QVariant& size) {
    m_size = size.toInt();
}