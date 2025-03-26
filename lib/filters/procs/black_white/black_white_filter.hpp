#pragma once

#include "i_filter.hpp"

class BlackWhiteFilter : public IFilter {
   public:
    ~BlackWhiteFilter() override = default;
    QString name() const override { return "black_white"; }
    void apply([[maybe_unused]] QImage& image) override;
    QString qml_path() const override {
        return QString("qrc:/qml/filters/black_white.qml");
    }
    EFilterType type() const override { return kBasic; }
};
