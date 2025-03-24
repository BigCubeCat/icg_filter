#include "imageprocessor.hpp"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QtAlgorithms>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include <qtmetamacros.h>

ImageProcessor::ImageProcessor() {
    connect(&m_watcher, &QFutureWatcher<QImage>::finished, this,
            &ImageProcessor::onImageProcessed);
}

void ImageProcessor::setSaved(bool saved) {
    m_saved = saved;
    if (m_has_edited) {
        m_has_edited = false;
        m_original = QImage(m_edited);
    }
}

bool ImageProcessor::is_saved() const {
    return m_saved;
}

QImage ImageProcessor::image() const {
    return m_edited;
}

void ImageProcessor::setImage(QImage new_image) {
    m_original = std::move(new_image);
    m_edited = QImage(m_original);
    m_saved = true;
    m_has_edited = false;
    emit rerender();
}

void ImageProcessor::applyFilter(IFilter* filter) {
    m_filter = filter;
    m_edited = QImage(m_original);
    QApplication::setOverrideCursor(Qt::CursorShape::WaitCursor);
    QFuture<QImage> future = QtConcurrent::run([this]() mutable {
        m_image = m_edited;
        m_filter->apply(m_image);
        return m_image;
    });

    m_watcher.setFuture(future);
}

void ImageProcessor::apply() {}

void ImageProcessor::save(const std::string& filename,
                          const std::string& format) {
    m_edited.save(filename.c_str(), format.c_str());
    m_original = m_edited;
}

void ImageProcessor::done() {
    QApplication::setOverrideCursor(Qt::CursorShape::ArrowCursor);
    m_need_process = false;
    m_saved = false;
    m_has_edited = true;
    emit rerender();
}

void ImageProcessor::onImageProcessed() {
    m_edited = m_watcher.result();
    done();
}
