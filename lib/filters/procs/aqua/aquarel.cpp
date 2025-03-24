//
// Created by anton on 3/19/25.
//

#include "aquarel.hpp"

#include "Convolution.hpp"
void aquarel::apply(QImage& image) {
    QImage tmp = image;
    const int ks = 7;
    const int st = -ks / 2;
    const int fn = (ks - 1) / 2;
    const int iw = image.width();
    const int ih = image.height();
    for (int y = 0; y < ih; y++) {
        for (int x = 0; x < iw; x++) {
            std::vector<int> reds;
            std::vector<int> greens;
            std::vector<int> blues;
            for (int ki = st; ki <= fn; ++ki) {
                for (int kj = st; kj <= fn; ++kj) {
                    if (y + ki >= 0 && y + ki < ih && x + kj >= 0 &&
                        x + kj < iw) {
                        QColor color = image.pixel(x + kj, y + ki);
                        reds.push_back(color.red());
                        greens.push_back(color.green());
                        blues.push_back(color.blue());
                    }
                }
            }
            std::sort(reds.begin(), reds.end());
            std::sort(greens.begin(), greens.end());
            std::sort(blues.begin(), blues.end());
            tmp.setPixelColor(
                x, y,
                QColor(reds[reds.size() / 2], greens[greens.size() / 2],
                       blues[blues.size() / 2]));
        }
    }

    QVector<QVector<int>> m_weights;
    int cnt = 3;
    for (int i = 0; i < cnt; i++) {
        m_weights.push_back(QVector<int>(cnt));
        for (int j = 0; j < cnt; j++) {
            if (i != j || j != 1) {
                m_weights[i][j] = -1;
            } else {
                m_weights[i][j] = 9;
            }
        }
    }
    Convolution::convolution(tmp, m_weights, 1, false, true);
    image = tmp;
}