#pragma once

#include <qvariant.h>
#include "i_filter.hpp"

class BlackWhiteFloydSteinbergFilter : public IFilter {
    Q_OBJECT
    Q_PROPERTY(
        int red_quants READ get_quants WRITE set_quants NOTIFY cntChanged)

   public:
    QString name() const override { return "bwfsf"; }
    void apply(QImage& image) override;
    QString qml_path() const override {
        return "qrc:/qml/filters/BWFloydSteinbergFilter.qml";
    }
    EFilterType type() const override { return kDithering; }

    Q_INVOKABLE int get_quants() const { return m_cnt_quants; }
    Q_INVOKABLE void set_quants(const QVariant& value) {
        m_cnt_quants = value.toInt();
    }

   signals:
    void cntChanged();

   private:
    int m_cnt_quants = 2;
};
