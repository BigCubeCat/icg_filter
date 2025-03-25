#include "imageprocessor.hpp"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QtAlgorithms>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include <qlogging.h>
#include <qtmetamacros.h>

ImageProcessor::ImageProcessor() {
    connect(&m_watcher, &QFutureWatcher<QImage>::finished, this,
            &ImageProcessor::onImageProcessed);
}

void ImageProcessor::setSaved(bool /* saved */) {
    m_original = QImage(m_edited);
}

QImage ImageProcessor::image() const {
    if (m_show_edited) {
        return m_edited;
    }
    return m_original;
}

void ImageProcessor::setImage(QImage new_image) {
    m_original = std::move(new_image);
    m_edited = QImage(m_original);
    emit rerender();
}

void ImageProcessor::applyFilter(IFilter* filter) {
    if (!m_done) {
        return;
    }
    m_done = false;
    m_filter = filter;
    m_edited = QImage(m_original);
    QApplication::setOverrideCursor(Qt::CursorShape::WaitCursor);
    QFuture<QImage> future = QtConcurrent::run([this]() mutable {
        const auto p1 = std::chrono::system_clock::now();
        const auto begin =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                p1.time_since_epoch())
                .count();
        m_image = m_edited;
        m_filter->apply(m_image);
        const auto p2 = std::chrono::system_clock::now();
        const auto end = std::chrono::duration_cast<std::chrono::milliseconds>(
                             p2.time_since_epoch())
                             .count();
        qDebug() << "time spent: " << end - begin << "\n";
        return m_image;
    });

    m_watcher.setFuture(future);
}

void ImageProcessor::save(const std::string& filename,
                          const std::string& format) {
    qDebug() << filename << "." << format << "\n";
    m_edited.save(filename.c_str(), format.c_str());
    m_original = m_edited;
}

void ImageProcessor::done() {
    QApplication::setOverrideCursor(Qt::CursorShape::ArrowCursor);
    emit rerender();
}

void ImageProcessor::onImageProcessed() {
    m_done = true;
    m_edited = m_watcher.result();
    done();
}

void ImageProcessor::toggleView() {
    m_show_edited = !m_show_edited;
    emit rerender();
}
