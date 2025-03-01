#include "state.hpp"

#include <QFileInfo>
#include <utility>

StateSingleton& StateSingleton::instance() {
    static StateSingleton inst;
    return inst;
}

void StateSingleton::setController(SignalController* controller) {
    m_controller_ptr = controller;
}

SignalController* StateSingleton::controller() {
    return m_controller_ptr;
}

void StateSingleton::selectFilter(e_filter filter) {
    // тут нужно поставить переменные по умолчанию
}

e_filter StateSingleton::currentFilter() const {
    return m_selected_filter;
}

void StateSingleton::setFilename(std::string filename) {
    m_filename = std::move(filename);

    QFileInfo file_info(QString::fromStdString(m_filename));
    m_folder = file_info.absolutePath().toStdString();
    m_file_format = file_info.completeSuffix().toStdString();
}

std::string StateSingleton::filename() const {
    return m_filename;
}

void StateSingleton::setFileFormat(std::string format) {
    m_file_format = std::move(format);
}

std::string StateSingleton::fileFormat() const {
    return m_file_format;
}

std::string StateSingleton::folder() const {
    return m_folder;
}

void StateSingleton::setImage(QImage new_image) {
    m_image = std::move(new_image);
}

QImage& StateSingleton::image() {
    return m_image;
}
