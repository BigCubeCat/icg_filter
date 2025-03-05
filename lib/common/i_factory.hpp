#pragma once

#include "i_filter.hpp"
class IFactory {
   public:
    virtual IFilter* filter(const std::string& name, const QJsonObject& args);
};
