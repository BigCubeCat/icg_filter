#include "imageprocessor.hpp"
#include <qlogging.h>

#include <algorithm>

ImageProcessor::ImageProcessor(IFactory* factory) : m_factory(factory) {}

void ImageProcessor::filter(const std::string& name, const QJsonObject& args) {
    if (!m_factory) {
        // TODO(bigcubecat): show error
        return;
    }
    m_factory->filter(name, args)->apply(m_original);
    m_has_edited = true;
    emit rerender();
}

void ImageProcessor::setSaved(bool saved) {
    m_saved = saved;
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
}

void ImageProcessor::zoomHandler(int old_zoom) {
    emit zoom(old_zoom, m_current_zoom);
    emit rerender();
}

void ImageProcessor::zoomIn() {
    int old_zoom = m_current_zoom;
    qDebug() << "zoomIn(): " << old_zoom << m_current_zoom;
    m_current_zoom += kZoomStep;
    m_current_zoom = std::min<double>(m_current_zoom, 3.0F);
    zoomHandler(old_zoom);
}

void ImageProcessor::zoomOut() {
    int old_zoom = m_current_zoom;
    qDebug() << "zoomOut(): " << old_zoom << m_current_zoom;
    m_current_zoom -= kZoomStep;
    m_current_zoom = std::max<double>(m_current_zoom, 0.1F);
    zoomHandler(old_zoom);
}

void ImageProcessor::zoomReset() {
    qDebug() << "zoomReset()";
    m_current_zoom = 1;
    zoomHandler(1);
    emit rerender();
}
