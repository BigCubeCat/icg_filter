#include "imageprocessor.hpp"

#include <qalgorithms.h>
#include <qapplication.h>
#include <qdebug.h>
#include <qlogging.h>
#include <qmessagebox.h>

#include <qtmetamacros.h>

ImageProcessor::ImageProcessor(std::mutex* mut, std::condition_variable* cond)
    : m_mutex_ptr(mut), m_cond_var_ptr(cond) {}

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
    m_image = QImage(m_original);
    QApplication::setOverrideCursor(Qt::CursorShape::WaitCursor);
    {
        std::lock_guard lk(*m_mutex_ptr);
        m_need_process = true;
    }
    m_cond_var_ptr->notify_one();
}

void ImageProcessor::apply() {
    m_filter->apply(m_image);
}

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
    m_edited = m_image;
    m_image.fill(QColor(0, 0, 255));
    emit rerender();
}
