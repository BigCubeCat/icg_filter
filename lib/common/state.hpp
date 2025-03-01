/*!
 * \file в этом файле описывается класс хранящий состояние
 */
#pragma once

#include <QJsonObject>
#include <QObject>
#include <mutex>
#include <optional>
#include <string>
#include <unordered_map>
#include "e_filter.hpp"

/*!
 * \brief хранит состояние
 * Состояние включает в себя имена файлов, выбранный инструмент и тп
 * Singleton. Thread-Safe
 */
class StateSingleton {
   private:
    StateSingleton() = default;

    std::mutex m_mutex;
    e_filter m_selected_filter;

    int m_width = 600;
    int m_height = 400;

    std::unordered_map<std::string, QJsonObject> m_config;

   public:
    StateSingleton(const StateSingleton&) = delete;
    StateSingleton& operator=(const StateSingleton&) = delete;

    /// вернуть сущность объекта
    static StateSingleton& instance();

    /// установить геометрию
    void setGeometry(int w, int h);
    /// ширина холста
    int width() const;
    /// высота холста
    int height() const;

    /// Задает конфиг
    void setConfig(const std::string& name, const QJsonObject& value);
    /// отдает значение конфига по имени переменной. в случае отсутствия std::nullopt
    std::optional<QJsonObject> getConfig(const std::string& name);

    /// установаить инструмент
    void selectFilter(e_filter filter);
    /// возращает тэг текущего инструмента
    e_filter currentFilter() const;
};
