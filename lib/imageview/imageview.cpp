#include "imageview.hpp"
#include <qlogging.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qwidget.h>

#include "../common/state.hpp"

#include "ui_imageview.h"

ImageView::ImageView(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::ImageView) {
    m_ui->setupUi(this);
    m_loading =
        QImage("assets/loading.png").scaled(64, 64, Qt::KeepAspectRatio);
    m_no_image = QImage("assets/no.png").scaled(64, 64, Qt::KeepAspectRatio);
    m_view = m_no_image;
}

void ImageView::paintEvent([[maybe_unused]] QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    setFixedSize(m_view.size() + QSize(10, 10));
    painter.drawImage(0, 0, m_view);
}

ImageView::~ImageView() {
    delete m_ui;
}

void ImageView::updateImage() {
    auto* imp = StateSingleton::instance().imageProcessor();
    m_view = imp->image();
    auto zoom_factor = imp->zoomFacor();
    QSize new_size = m_view.size() * zoom_factor;
    qDebug() << new_size << "->" << zoom_factor;
    m_view = m_view.scaled(new_size, Qt::KeepAspectRatio);
    update();
}

void ImageView::loading() {
    m_view = m_loading;
    update();
}
