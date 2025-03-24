//
// Created by anton on 3/11/25.
//

#include "sharpness.hpp"
#include <QVariant>

#include "Convolution.hpp"
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
    Convolution::convolution(image, m_weights, sum_weight? sum_weight : 1,false, true);
}

void SharpnessFilter::onReset() {
    m_weights.clear();
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