#pragma once

#include <QImage>

#include <QImage>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "omp.h"

class Convolution {
   public:
    static void convolution(QImage& image, const QVector<QVector<int>>& kernel, const int &denum, bool absolute = false, bool continousBorder = false);
};
