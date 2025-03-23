#pragma once

#include <qobject.h>
#include <QImage>
#include "imageprocessor.hpp"

class ImagePainter : public QObject {
    Q_OBJECT
    Q_PROPERTY(QImage image READ image WRITE setImage NOTIFY imageChanged)
   public:
    explicit ImagePainter(ImageProcessor* processor);

    QImage image() const;
    void setImage(const QImage& newImage);

   signals:
    void imageChanged();

   public slots:
    void updateImage();

   private:
    ImageProcessor* m_processor;
    QImage m_image;
};
