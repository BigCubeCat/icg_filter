/*!
 * \file в этом файле описывается класс хранящий состояние
 */
#pragma once

#include "e_filter.hpp"
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

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

  std::unordered_map<std::string, std::shared_ptr<void *>> m_variables;

public:
  StateSingleton(const StateSingleton &) = delete;
  StateSingleton &operator=(const StateSingleton &) = delete;

  /// вернуть сущность объекта
  static StateSingleton &instance();

  /// установить геометрию
  void setGeometry(int w, int h);
  /// ширина холста
  int width() const;
  /// высота холста
  int height() const;

  /// установаить инструмент
  void selectFilter(e_filter filter);
  /// возращает тэг текущего инструмента
  e_filter currentFilter() const;
};
