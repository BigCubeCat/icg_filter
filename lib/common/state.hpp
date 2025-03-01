/*!
 * \file в этом файле описывается класс хранящий состояние
 */
#pragma once

#include <QImage>
#include <QJsonObject>
#include <QObject>
#include <mutex>
#include <optional>
#include <string>
#include <unordered_map>
#include "../signalcontroller/signalcontroller.hpp"
#include "e_filter.hpp"

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

    std::unordered_map<std::string, QJsonObject> m_config;
    e_filter m_selected_filter;

    std::string m_filename;
    std::string m_file_format;
    std::string m_folder;
    QImage m_prev_image;
    QImage m_image;

   public:
    StateSingleton(const StateSingleton&) = delete;
    StateSingleton& operator=(const StateSingleton&) = delete;

    /// вернуть сущность объекта
    static StateSingleton& instance();

    void setController(SignalController* controller);
    SignalController* controller();

    /// Задает конфиг
    void setConfig(const std::string& name, const QJsonObject& value);
    /// отдает значение конфига по имени переменной. в случае отсутствия std::nullopt
    std::optional<QJsonObject> getConfig(const std::string& name);

    /// установаить инструмент
    void selectFilter(e_filter filter);
    /// возращает тэг текущего инструмента
    e_filter currentFilter() const;

    void setFilename(std::string filename);
    std::string filename() const;
    void setFileFormat(std::string format);
    std::string fileFormat() const;
    std::string folder() const;

    void setImage(QImage new_image);
    QImage& image();
};
