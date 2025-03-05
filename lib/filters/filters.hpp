#pragma once

#include "../common/i_factory.hpp"

class Filters : public IFactory {
   public:
    IFilter* filter(const std::string& name, const QJsonObject& args) override;
};
