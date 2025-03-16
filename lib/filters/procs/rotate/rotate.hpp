#pragma once

#include <QImage>
#include <QJsonObject>

#include "i_filter.hpp"

class RotateFilter : public IFilter {
    Q_OBJECT
    Q_PROPERTY(int angle READ angle WRITE setAngle NOTIFY angleChanged)

   public:
    ~RotateFilter() override = default;

    QString qml_path() const override {
        return QString("qml/filters/rotate.qml");
    }

    QString name() const override { return "rotate"; }

    EFilterType type() const override { return kBasic; }

    double angle() const { return m_angle; }

    void setAngle(int value) {
        if (m_angle != value) {
            m_angle = value;
            emit angleChanged(value);
        }
    }

   signals:
    void angleChanged(double value);

   private:
    int m_angle = 0;

   public:
    void apply([[maybe_unused]] QImage& image) override;
};
