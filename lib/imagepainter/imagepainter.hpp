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

   private:
    ImageProcessor* m_processor;
    QPointF m_last_drag_pos;
    QGraphicsScene m_scene;
    std::unique_ptr<QGraphicsPixmapItem> m_pixmap_item;

   protected:
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
};
