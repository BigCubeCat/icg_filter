#pragma once

#include <qjsonobject.h>
#include <QImage>
#include <QJsonObject>
#include "i_filter.hpp"

class IdleFilter : public IFilter {
   public:
    ~IdleFilter() = default;

    QJsonObject json() const override { return QJsonObject(); }

    std::string name() const override { return "idle"; }

    void apply([[maybe_unused]] QImage& image) override {}
};
