#pragma once
#include <QVariant>

#include "i_filter.hpp"

class OrderedDitheringFilter : public IFilter {
    Q_OBJECT

    Q_PROPERTY(int red_quants READ get_red_quants WRITE set_red_quants NOTIFY
                   cntRedChanged)
    Q_PROPERTY(int green_quants READ get_green_quants WRITE set_green_quants
                   NOTIFY cntGreenChanged)
    Q_PROPERTY(int blue_quants READ get_blue_quants WRITE set_blue_quants NOTIFY
                   cntBLueChanged)
   public:
    QString name() const override { return "odf"; }
    void apply(QImage& image) override;
    QString qml_path() const override {
        return "qrc:/qml/filters/orderedDithering.qml";
    }
    EFilterType type() const override { return kDithering; }

    Q_INVOKABLE int get_red_quants() const { return m_cnt_red_quants; }
    Q_INVOKABLE int get_green_quants() const { return m_cnt_green_quants; }
    Q_INVOKABLE int get_blue_quants() const { return m_cnt_blue_quants; }
    Q_INVOKABLE void set_red_quants(const QVariant& value) {
        m_cnt_red_quants = value.toInt();
    }
    Q_INVOKABLE void set_green_quants(const QVariant& value) {
        m_cnt_green_quants = value.toInt();
    }
    Q_INVOKABLE void set_blue_quants(const QVariant& value) {
        m_cnt_blue_quants = value.toInt();
    }

   signals:
    void cntRedChanged();
    void cntGreenChanged();
    void cntBLueChanged();

   private:
    int m_cnt_red_quants = 2;
    int m_cnt_green_quants = 2;
    int m_cnt_blue_quants = 2;
};
