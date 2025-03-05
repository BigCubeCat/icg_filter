/*!
 * \file в этом файле описывается класс хранящий состояние
 */
#pragma once

#include <QImage>
#include <QJsonObject>
#include <QObject>
#include <csignal>
#include <mutex>
#include <optional>
#include <string>
#include <unordered_map>
#include "../signalcontroller/signalcontroller.hpp"

#include "fileprocessor.hpp"
#include "imageprocessor.hpp"

/*!
 * \brief хранит состояние
 * Состояние включает в себя имена файлов, выбранный инструмент и тп
 * Singleton. Thread-Safe
 */
class StateSingleton {
   private:
    std::mutex m_mutex;
    StateSingleton() = default;

    SignalController* m_controller_ptr;
    ImageProcessor* m_processor;
    FileProcessor* m_file_processor;

    std::unordered_map<std::string, QJsonObject> m_config;

   public:
    StateSingleton(const StateSingleton&) = delete;
    StateSingleton& operator=(const StateSingleton&) = delete;
    /// вернуть сущность объекта
    static StateSingleton& instance();

    void setController(SignalController* controller);
    SignalController* controller();

    void setImageProcessor(ImageProcessor* proc);
    ImageProcessor* imageProcessor();

    void setFileProcessor(FileProcessor* proc);
    FileProcessor* fileProcessor();

    /// Задает конфиг
    void setConfig(const std::string& name, const QJsonObject& value);
    /// отдает значение конфига по имени переменной. в случае отсутствия std::nullopt
    std::optional<QJsonObject> getConfig(const std::string& name);
};
