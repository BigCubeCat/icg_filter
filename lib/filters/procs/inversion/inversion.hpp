#pragma once
#include "i_filter.hpp"

class InversionFilter : public IFilter {
   public:

    QString name() const override { return "inversion"; }

    void apply(QImage& image) override;
    QString qml_path() const override {
        return "qrc:/qml/filters/inversion.qml";
    }
    EFilterType type() const override { return kPixel; }
};
