#include "imageprocessor.hpp"

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
