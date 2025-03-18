#pragma once

#include <QImage>

#include "omp.h"

class Convolution {
   public:
    static void convolution(QImage& image, const QVector<QVector<int>>& kernel,
                            const int& denum);
};
