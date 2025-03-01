#include "imageview.hpp"
#include <qlogging.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qwidget.h>

#include "ui_imageview.h"

ImageView::ImageView(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::ImageView) {
    m_ui->setupUi(this);
    m_loading =
        QImage("assets/loading.png").scaled(64, 64, Qt::KeepAspectRatio);
    m_no_image = QImage("assets/no.png").scaled(64, 64, Qt::KeepAspectRatio);
    updateImage(m_no_image);
}

void ImageView::paintEvent([[maybe_unused]] QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawImage(0, 0, m_view);
}

ImageView::~ImageView() {
    delete m_ui;
}

void ImageView::updateImage(const QImage& image) {
    m_view = image;
    setFixedSize(m_view.size());
    update();
}

void ImageView::loading() {
    updateImage(m_loading);
}
