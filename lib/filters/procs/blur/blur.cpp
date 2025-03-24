//
// Created by anton on 3/11/25.
//

#include "blur.hpp"

#include <QVariant>

#include "Convolution.hpp"
BlurFilter::BlurFilter(int cnt, int off) {
    sum_weight = 0;
    for (int i = 0; i < cnt; i++) {
        m_weights.push_back(QVector<int>(cnt));
        for (int j = 0; j < cnt; j++) {
            int offi = std::min(i, cnt - 1 - i);
            int offj = std::min(j, cnt - 1 - j);
            m_weights[i][j] = offi + offj + off;
            sum_weight += m_weights[i][j];
            emit set_weight(QVariant(j * cnt + i), QVariant(m_weights[i][j]));
        }
    }
}
void BlurFilter::apply(QImage& image) {

    if (m_weights.size() < 7) {
        Convolution::convolution(image, m_weights, sum_weight? sum_weight : 1);
    }
    else {
        QImage tmp = image;
        const int ks = m_weights.size();
        const int st = -ks / 2;
        const int fn = (ks - 1) / 2;
        const int iw = image.width();
        const int ih = image.height();
        for (int y = 0; y < ih; y++) {
            for (int x = 0; x < iw; x++) {
                std::vector<int>reds;
                std::vector<int>greens;
                std::vector<int>blues;
                for (int ki = st; ki <= fn; ++ki) {
                    for (int kj = st; kj <= fn; ++kj) {
                        if (y + ki >= 0 && y + ki < ih && x  + kj >= 0 && x + kj < iw ) {
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
                tmp.setPixelColor(x, y, QColor(reds[reds.size()/2], greens[greens.size()/2], blues[blues.size()/2]));
            }
        }
        image = tmp;
    }

}
void BlurFilter::onChangedSize(const QVariant& size) {
    int cnt = size.toInt();
    this->size = cnt;
    int off = 0;
    if (cnt == 5) {
        off = 1;
    }
    m_weights.clear();
    sum_weight = 0;
    for (int i = 0; i < cnt; i++) {
        m_weights.push_back(QVector<int>(cnt));
        for (int j = 0; j < cnt; j++) {
            int offi = std::min(i, cnt - 1 - i);
            int offj = std::min(j, cnt - 1 - j);
            m_weights[i][j] = offi + offj + off;
            sum_weight += m_weights[i][j];
            emit set_weight(QVariant(j * cnt + i), QVariant(m_weights[i][j]));
        }
    }
}
void BlurFilter::onChangedWeight(const QVariant& rows, const QVariant& index,
                           const QVariant& value) {
    sum_weight -= m_weights[index.toInt()%rows.toInt()][index.toInt()/rows.toInt()];
    m_weights[index.toInt()%rows.toInt()][index.toInt()/rows.toInt()] = value.toInt();
    sum_weight += value.toInt();
}

