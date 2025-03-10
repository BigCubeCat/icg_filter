#pragma once

#include <memory>
#include "i_filter.hpp"

class IFactory {
   public:
    /// Возращает указатель на фильтр по имени
    virtual IFilter* filter(const std::string& name) = 0;
    /// Возращает Вектор всех фильтров
    virtual std::vector<IFilter*> all_filters() = 0;
    /// Добавляет фильтр в коллекцию
    virtual void register_filter(const std::string& name,
                                 std::shared_ptr<IFilter> filter_ptr) = 0;
};
