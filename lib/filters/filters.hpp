#pragma once

#include <unordered_map>
#include "../common/i_factory.hpp"

/*!
 * \brief Фабрика с фильтрами
 */
class FiltersFactory : public IFactory {
   private:
    std::unordered_map<std::string, std::shared_ptr<IFilter>> m_filters;

   public:
    /// Возращает указатель на фильтр по имени
    IFilter* filter(const std::string& name) override;
    /// Возращает Вектор всех фильтров
    std::vector<IFilter*> all_filters() override;
    /// Добавляет фильтр в коллекцию
    void register_filter(const std::string& name,
                         std::shared_ptr<IFilter> filter_ptr) override;
};
