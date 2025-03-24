#pragma once
#include "i_filter.hpp"

class SobelsFilter : public IFilter {
    Q_OBJECT
    Q_PROPERTY(int threshold READ getThreshold WRITE setThreshold NOTIFY
                   thresholdChanged);

   public:
    SobelsFilter();
    QString name() const override { return "sobels"; }
    void apply(QImage& image) override;
    QString qml_path() const override { return "qrc:/qml/filters/sobels.qml"; }
    EFilterType type() const override { return kPixel; }

   signals:
    void thresholdChanged(int threshold);

   public slots:
    void setThreshold(const QVariant& threshold);
    int getThreshold() const { return m_threshold; }

   private:
    int m_threshold = 0;
    QVector<QVector<int>> first_step;
    QVector<QVector<int>> second_step;
};
