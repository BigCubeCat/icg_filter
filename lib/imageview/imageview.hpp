#pragma once

#include <QJsonObject>
#include <QWidget>
#include "imageprocessor.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class ImageView;
}
QT_END_NAMESPACE

class ImageView : public QWidget {
    Q_OBJECT
   public:
    explicit ImageView(ImageProcessor* im, QWidget* parent = nullptr);
    ~ImageView() override;

   protected:
    void paintEvent(QPaintEvent* event) override;

   private:
    Ui::ImageView* m_ui;
    ImageProcessor* m_im;
    QImage m_view;
    QImage m_loading;
    QImage m_no_image;
    QJsonObject m_current;

   public slots:
    void updateImage();
    void loading();
};
