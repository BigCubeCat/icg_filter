#include "imagepainter.hpp"
#include <qdebug.h>
#include <qlogging.h>

#include "ui_imagepainter.h"

ImagePainter::ImagePainter(ImageProcessor* processor, QWidget* parent)
    : QWidget(parent), m_processor(processor), m_ui(new Ui::ImagePainter) {
    m_ui->setupUi(this);
}

void ImagePainter::setView(const QImage& image) {
    qDebug() << image.isNull();
    auto* pixmap_item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    m_scene.addItem(pixmap_item);
    m_scene.setSceneRect(image.rect());
}
