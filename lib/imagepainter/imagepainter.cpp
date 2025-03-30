#include "imagepainter.hpp"
#include <qdebug.h>
#include <qgraphicsview.h>
#include <qlogging.h>

const float kScaleIn = 1.05;
const float kScaleOut = 0.95;

ImagePainter::ImagePainter(ImageProcessor* processor, QWidget* parent)
    : QGraphicsView(parent), m_processor(processor) {
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void ImagePainter::setView(const QImage& image) {
    m_pixmap_item =
        std::make_unique<QGraphicsPixmapItem>(QPixmap::fromImage(image));
    m_scene.addItem(m_pixmap_item.get());
    m_rect = image.rect();
    m_scene.setSceneRect(m_rect);
    setRenderHint(m_hint);
    this->setScene(&m_scene);
}

void ImagePainter::updateRenderHint(const QPainter::RenderHint& hint) {
    m_hint = hint;
    setRenderHint(m_hint);
    update();
}

void ImagePainter::wheelEvent(QWheelEvent* event) {
    if (event->angleDelta().y() > 0)
        scale(kScaleIn, kScaleIn);
    else
        scale(kScaleOut, kScaleOut);
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

void ImagePainter::zoomIn() {
    scale(kScaleIn, kScaleIn);
}

void ImagePainter::zoomOut() {
    scale(kScaleOut, kScaleOut);
}

void ImagePainter::zoomFit() {
    zoomReset();
    auto size = this->size();
    const auto rect_width = static_cast<float>(size.width());
    const auto rect_height = static_cast<float>(size.height());
    const auto img_width = static_cast<float>(m_rect.width());
    const auto img_height = static_cast<float>(m_rect.height());
    auto k = (img_width > img_height) ? (rect_width / img_width)
                                      : (rect_height / img_height);
    scale(k, k);
}

void ImagePainter::zoomReset() {
    m_pixmap_item->setTransform(QTransform().scale(1, 1));
}
