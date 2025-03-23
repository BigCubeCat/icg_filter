#include "imagepainter.hpp"
#include <qdebug.h>
#include <qlogging.h>

ImagePainter::ImagePainter(ImageProcessor* processor)
    : QObject(nullptr), m_processor(processor) {}

QImage ImagePainter::image() const {
    return m_image;
}

void ImagePainter::updateImage() {
    qDebug() << "ImagePainter::updateImage()\n";
    setImage(m_processor->image());
    qDebug() << "ImagePainter::updateImage() end \n";
}

void ImagePainter::setImage(const QImage& newImage) {
    if (m_image != newImage) {
        m_image = newImage;
        emit imageChanged();
    }
}
