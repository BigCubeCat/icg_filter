#pragma once
#include "MedianFinder.h"
#include "i_filter.hpp"
#include "procs/blur/blur.hpp"
#include "procs/sharp/sharpness.hpp"

class aquarel : public IFilter {

    Q_OBJECT
    Q_PROPERTY(double size READ getSize WRITE setSize NOTIFY sizeChanged())
   public:
    QString name() const override { return "aquarel"; }
    void apply(QImage& image) override;
    QString qml_path() const override { return "qrc:/qml/filters/aquarel.qml"; }
    EFilterType type() const override { return kMatrix; }

    Q_INVOKABLE double getSize() const;
    Q_INVOKABLE void setSize(const QVariant& size);
   signals:
    void sizeChanged();

   private:
    int m_size = 7;
    SharpnessFilter m_sharp;
};
