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
