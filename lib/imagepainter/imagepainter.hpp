#pragma once

#include <qevent.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qobject.h>
#include <qwidget.h>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QScrollBar>

#include "imageprocessor.hpp"

class ImagePainter : public QGraphicsView {
    Q_OBJECT
   public:
    explicit ImagePainter(ImageProcessor* processor, QWidget* parent = nullptr);

    void setView(const QImage& image);
    void updateRenderHint(const QPainter::RenderHint& hint);

   private:
    ImageProcessor* m_processor;
    QPixmap m_pixmap;
    QPainter::RenderHint m_hint = QPainter::NonCosmeticBrushPatterns;
    QPointF m_last_drag_pos;
    QGraphicsScene m_scene;
    std::unique_ptr<QGraphicsPixmapItem> m_pixmap_item;

    QRect m_rect;

   protected:
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

   public slots:
    void zoomIn();
    void zoomOut();
    void zoomFit();
    void zoomReset();
};
