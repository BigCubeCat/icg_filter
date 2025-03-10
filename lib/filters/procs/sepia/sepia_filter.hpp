#pragma once

#include <QImage>
#include <QJsonObject>

#include "i_filter.hpp"

class SepiaFilter : public IFilter {
    Q_OBJECT
    Q_PROPERTY(int percent READ percent WRITE setPercent NOTIFY percentChanged)

   public:
    ~SepiaFilter() override = default;

    QString qml_path() const override {
        return QString("qml/filters/sepia.qml");
    }

    QString name() const override { return "sepia"; }

    EFilterType type() const override { return kPixel; }

    double percent() const { return m_percent; }
    void setPercent(int value) {
        if (m_percent != value) {
            m_percent = value;
            emit percentChanged(value);
        }
    }

   signals:
    void percentChanged(double value);

   private:
    int m_percent = 0;

   public:
    void apply([[maybe_unused]] QImage& image) override;
};
