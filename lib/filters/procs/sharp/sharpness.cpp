//
// Created by anton on 3/11/25.
//

#include "sharpness.hpp"
#include <QVariant>
SharpnessFilter::SharpnessFilter() {
    sum_weight = 0;
    for (int i = 0; i < cnt; i++) {
        m_weights.push_back(QVector<int>(cnt));
        for (int j = 0; j < cnt; j++) {
            int offi = std::min(i, cnt - 1 - i);
            int offj = std::min(j, cnt - 1 - j);
            m_weights[i][j] = -offi -offj;
            if (i == 1 && j == 1) {
                m_weights[i][j] = 5;
            }
            sum_weight += m_weights[i][j];

            emit set_weight(QVariant(j * cnt + i), QVariant(m_weights[i][j]));
        }
    }
}
void SharpnessFilter::apply(QImage& image) {
    QImage save = image;
    for (int i = 0; i < image.height(); i++) {
        for (int j = 0; j < image.width(); j++) {
            int localr = 0, localg = 0, localb = 0; ;
            for (int k = 0; k < cnt; k++) {
                for (int l = 0; l < cnt; l++) {
                    int abs_y = i + k - (cnt / 2);
                    int abs_x = j + l - (cnt / 2);
                    if (abs_y < 0 || abs_y >= image.height() || abs_x < 0 || abs_x >= image.width()) {
                        localr += 0;
                        localg += 0;
                        localb += 0;
                    } else {
                        localr += save.pixelColor(abs_x,abs_y).red() * m_weights[k][l];
                        localg += save.pixelColor(abs_x,abs_y).green() * m_weights[k][l];
                        localb += save.pixelColor(abs_x,abs_y).blue() * m_weights[k][l];
                    }
                }
            }
            QColor color = QColor();
            color.setRed(localr / sum_weight > 255 ? 255 : localr /sum_weight < 0 ? 0 : localr / sum_weight);
            color.setGreen(localg / sum_weight > 255 ? 255 : localg /sum_weight < 0 ? 0 : localg / sum_weight);
            color.setBlue(localb / sum_weight > 255 ? 255 : localb /sum_weight < 0 ? 0 : localb / sum_weight);
            image.setPixelColor(j, i, color);
        }
    }

}

void SharpnessFilter::onReset() {
    sum_weight = 0;
    for (int i = 0; i < cnt; i++) {
        m_weights.push_back(QVector<int>(cnt));
        for (int j = 0; j < cnt; j++) {
            int offi = std::min(i, cnt - 1 - i);
            int offj = std::min(j, cnt - 1 - j);
            m_weights[i][j] = -(offi + offj);
            if (i == 1 && j == 1) {
                m_weights[i][j] = 5;
            }
            sum_weight += m_weights[i][j];
            emit set_weight(QVariant(j * cnt + i), QVariant(m_weights[i][j]));
        }
    }
}
void SharpnessFilter::onChangedWeight(const QVariant& rows,
                                      const QVariant& index,
                                      const QVariant& value) {
    sum_weight -= m_weights[index.toInt()%rows.toInt()][index.toInt()/rows.toInt()];
    m_weights[index.toInt()%rows.toInt()][index.toInt()/rows.toInt()] = value.toInt();
    sum_weight += value.toInt();
}