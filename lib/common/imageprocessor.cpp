#include "imageprocessor.hpp"
#include <qtmetamacros.h>

#include <algorithm>

ImageProcessor::ImageProcessor() = default;

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
    emit rerender();
}

void ImageProcessor::applyFilter(IFilter* filter) {
    m_edited = m_original;
    filter->apply(m_edited);
    m_saved = false;
    m_has_edited = true;
    emit rerender();
}


