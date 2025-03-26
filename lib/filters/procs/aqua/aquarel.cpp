//
// Created by anton on 3/19/25.
//

#include "aquarel.hpp"

#include <QVariant>

#include "Convolution.hpp"

void aquarel::apply(QImage& image) {
    QImage tmp = image.copy();
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