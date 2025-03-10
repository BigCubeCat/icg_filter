#include "filters.hpp"

IFilter* FiltersFactory::filter(const std::string& name) {
    auto found_filter = m_filters.find(name);
    if (found_filter == m_filters.end()) {
        return nullptr;
    }
    return found_filter->second.get();
}

std::vector<IFilter*> FiltersFactory::all_filters() {
    std::vector<IFilter*> result;
    result.reserve(m_filters.size());
    for (const auto& item : m_filters) {
        result.push_back(item.second.get());
    }
    return result;
}

void FiltersFactory::register_filter(const std::string& name,
                                     std::shared_ptr<IFilter> filter_ptr) {
    m_filters[name] = std::move(filter_ptr);
}
