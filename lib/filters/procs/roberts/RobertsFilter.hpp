#pragma once
#include "i_filter.hpp"

class RobertsFilter : public IFilter {
    Q_OBJECT
    Q_PROPERTY(int threshold READ getThreshold WRITE setThreshold NOTIFY
                   thresholdChanged);

   public:
    RobertsFilter();
    QString name() const override { return "roberts"; }
    void apply(QImage& image) override;
    QString qml_path() const override { return "qrc:/qml/filters/roberts.qml"; }
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
