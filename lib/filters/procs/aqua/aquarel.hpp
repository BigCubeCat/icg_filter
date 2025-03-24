#pragma once
#include "i_filter.hpp"

class aquarel : public IFilter {

    Q_OBJECT

   public:
    QString name() const override { return "aquarel"; }
    void apply(QImage& image) override;
    QString qml_path() const override { return "qrc:/qml/filters/aquarel.qml"; }
    EFilterType type() const override { return kMatrix; }
};
