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

void StateSingleton::setImageProcessor(ImageProcessor* proc) {
    m_processor = proc;
}

ImageProcessor* StateSingleton::imageProcessor() {
    return m_processor;
}

void StateSingleton::setFileProcessor(FileProcessor* proc) {
    m_file_processor = proc;
}

FileProcessor* StateSingleton::fileProcessor() {
    return m_file_processor;
}

void StateSingleton::setConfig(const std::string& name,
                               const QJsonObject& value) {
    m_config[name] = value;
}

std::optional<QJsonObject> StateSingleton::getConfig(const std::string& name) {
    auto value = m_config.find(name);
    if (value == m_config.end()) {
        return std::nullopt;
    }
    return value->second;
}
