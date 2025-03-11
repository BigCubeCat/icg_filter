#pragma once

#include <QImage>
#include <QJsonObject>

#include "i_filter.hpp"

class MirrorFilter : public IFilter {
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

   public:
    ~MirrorFilter() override = default;

    QString qml_path() const override {
        return QString("qml/filters/mirror.qml");
    }

    QString name() const override { return "mirror"; }

    EFilterType type() const override { return kBasic; }

    int value() const { return m_value; }

    void setValue(int value) {
        if (m_value != value) {
            m_value = value;
            emit valueChanged(value);
        }
    }

   signals:
    void valueChanged(double value);

   private:
    int m_value = 0;

   public:
    void apply([[maybe_unused]] QImage& image) override;
};
