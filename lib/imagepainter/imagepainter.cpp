#include "imagepainter.hpp"
#include <qdebug.h>
#include <qgraphicsview.h>
#include <qlogging.h>

ImagePainter::ImagePainter(ImageProcessor* processor, QWidget* parent)
    : QGraphicsView(parent), m_processor(processor) {
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void ImagePainter::setView(const QImage& image) {
    m_pixmap_item =
        std::make_unique<QGraphicsPixmapItem>(QPixmap::fromImage(image));
    m_scene.addItem(m_pixmap_item.get());
    m_scene.setSceneRect(image.rect());
    this->setScene(&m_scene);
}

void ImagePainter::wheelEvent(QWheelEvent* event) {
    if (event->angleDelta().y() > 0)
        scale(1.1, 1.1);
    else
        scale(0.9, 0.9);
}

void ImagePainter::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton)
        m_last_drag_pos = event->position();
}

void ImagePainter::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        QPointF delta = event->position() - m_last_drag_pos;
        m_last_drag_pos = event->position();
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() -
                                        delta.x());
        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
    }
}
