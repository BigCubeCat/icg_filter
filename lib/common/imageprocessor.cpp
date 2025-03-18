#include "imageprocessor.hpp"

#include <qalgorithms.h>
#include <qdebug.h>
#include <qlogging.h>
#include <qmessagebox.h>

#include <qtmetamacros.h>

#include <algorithm>

ImageProcessor::ImageProcessor(std::mutex* mut, std::condition_variable* cond)
    : m_mutex_ptr(mut), m_cond_var_ptr(cond) {}

void ImageProcessor::setSaved(bool saved) {
    m_saved = saved;
    if (m_has_edited) {
        m_has_edited = false;
        m_original = m_edited;
    }
}

bool ImageProcessor::is_saved() const {
    return m_saved;
}

QImage ImageProcessor::image() const {
    if (m_saved || !m_has_edited) {
        return m_original;
    }
    return m_edited;
}

void ImageProcessor::setImage(QImage new_image) {
    m_original = std::move(new_image);
    m_saved = true;
    m_has_edited = false;
    emit rerender();
}

void ImageProcessor::zoomHandler(int old_zoom) {
    emit zoom(old_zoom, m_current_zoom);
    emit rerender();
}

void ImageProcessor::zoomIn() {
    int old_zoom = m_current_zoom;
    m_current_zoom += kZoomStep;
    m_current_zoom = std::min<double>(m_current_zoom, 3.0F);
    zoomHandler(old_zoom);
}

void ImageProcessor::zoomOut() {
    int old_zoom = m_current_zoom;
    m_current_zoom -= kZoomStep;
    m_current_zoom = std::max<double>(m_current_zoom, 0.1F);
    zoomHandler(old_zoom);
}

void ImageProcessor::zoomReset() {
    m_current_zoom = 1;
    zoomHandler(1);
}

void ImageProcessor::zoomFit(const QSize& size) {
    const auto view_width = size.width();
    const auto view_height = size.height();
    const auto image_width = m_original.width();
    const auto image_height = m_original.height();

    m_current_zoom = std::min<float>(
        static_cast<float>(view_width) / static_cast<float>(image_width),

        static_cast<float>(view_height) / static_cast<float>(image_height));
    zoomHandler(1);
}

void ImageProcessor::applyFilter(IFilter* filter) {
    m_filter = filter;
    m_edited = m_original;
    {
        std::lock_guard lk(*m_mutex_ptr);
        m_need_process = true;
    }
    m_cond_var_ptr->notify_one();
}

void ImageProcessor::apply() {
    m_filter->apply(m_edited);
}

void ImageProcessor::save(const std::string& filename,
                          const std::string& format) {
    qDebug() << "image processor " << filename << " " << format;
    m_edited.save(filename.c_str(), format.c_str());
}

void ImageProcessor::done() {
    m_need_process = false;
    m_saved = false;
    m_has_edited = true;
    emit rerender();
}
