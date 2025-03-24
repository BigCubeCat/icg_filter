#pragma once

#include <qgraphicsscene.h>
#include <qobject.h>
#include <qwidget.h>
#include <QGraphicsPixmapItem>
#include <QImage>

#include "imageprocessor.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class ImagePainter;
}
QT_END_NAMESPACE

class ImagePainter : public QWidget {
    Q_OBJECT
   public:
    explicit ImagePainter(ImageProcessor* processor, QWidget* parent = nullptr);

    ~ImagePainter() override { delete m_ui; }

    void setView(const QImage& image);

   private:
    ImageProcessor* m_processor;
    Ui::ImagePainter* m_ui;

    QGraphicsScene m_scene;
};
