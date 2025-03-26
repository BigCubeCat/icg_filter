//
// Created by anton on 3/11/25.
//

#include "blur.hpp"

#include <QVariant>
#include <queue>

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
    QImage im = image.copy();
    qDebug() << "Blur weights size is :" << m_weights.size();
    if (m_weights.size() < 7) {
        Convolution::convolution(im, m_weights, sum_weight? sum_weight : 1);
        image = im.copy();
    }
    else {
        QImage tmp = image.copy();
        const int ks = m_weights.size();
        const int ks2 = ks * ks;
        const int st = -ks / 2;
        const int fn = (ks - 1) / 2;
        const int iw = image.width();
        const int ih = image.height();
        for (int y = 0; y < ih; y++) {
            std::queue<int> reds;
            std::queue<int>greens;
            std::queue<int>blues;
            long long int sumr = 0;
            long long int sumg = 0;
            long long int sumb = 0;

            QColor ccolor = image.pixelColor(0,y);
            for (int k = 0; k < ks; k++) {
                for (int l = st; l <= fn; l++) {
                    if (k <= ks/2 || y+l < 0 || y+l >= ih) {
                        reds.push(ccolor.red());
                        sumr += ccolor.red();
                        greens.push(ccolor.green());
                        sumg += ccolor.green();
                        blues.push(ccolor.blue());
                        sumb += ccolor.blue();
                    } else {
                        QColor color = image.pixelColor(-1 + k + st,y + l);
                        reds.push(color.red());
                        sumr += color.red();
                        greens.push(color.green());
                        sumg += color.green();
                        blues.push(color.blue());
                        sumb += color.blue();
                    }
                }
            }

            for (int x = 0; x < iw; x++) {
                ccolor = image.pixelColor(x, y);
                for (int k = st; k <= fn; k++) {
                    sumr -= reds.front();
                    sumg -= greens.front();
                    sumb -= blues.front();
                    reds.pop();
                    greens.pop();
                    blues.pop();

                    if (x + fn >= iw || y+k< 0 || y+k >= ih) {
                        sumr += ccolor.red();
                        sumg += ccolor.green();
                        sumb += ccolor.blue();
                        reds.push(ccolor.red());
                        greens.push(ccolor.green());
                        blues.push(ccolor.blue());
                    } else {
                        QColor color = image.pixelColor(x + fn, y + k);
                        sumr += color.red();
                        sumg += color.green();
                        sumb += color.blue();
                        reds.push(color.red());
                        greens.push(color.green());
                        blues.push(color.blue());
                    }

                }
                tmp.setPixelColor(x, y, QColor(sumr/ks2, sumg/ks2, sumb/ks2));
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

