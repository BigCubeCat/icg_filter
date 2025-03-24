#pragma once
#include <QVariant>

#include "i_filter.hpp"

class BWOrderedDitheringFilter : public IFilter {
    Q_OBJECT

    Q_PROPERTY(int quants READ get_quants WRITE set_quants NOTIFY cntChanged)
   public:
    QString name() const override { return "bw_odf"; }
    void apply(QImage& image) override;
    QString qml_path() const override {
        return "qrc:/qml/filters/ordered_dithering.qml";
    }
    EFilterType type() const override { return kPixel; }

    Q_INVOKABLE int get_quants() const { return m_cnt_quants; }
    Q_INVOKABLE void set_quants(const QVariant& value) {
        m_cnt_quants = value.toInt();
    }

   signals:
    void cntChanged();

   private:
    int m_cnt_quants = 2;
};
