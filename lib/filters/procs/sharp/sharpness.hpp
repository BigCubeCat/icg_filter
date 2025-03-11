#pragma once
#include "i_filter.hpp"

class SharpnessFilter : public IFilter {
    Q_OBJECT

   public:
    SharpnessFilter();
    QString name() const override { return "sharp"; }
    void apply(QImage& image) override;
    QString qml_path() const override { return "qrc:/qml/filters/sharp.qml"; }
    EFilterType type() const override { return kMatrix; }

   signals:
    void set_weight(const QVariant& index, const QVariant& value);

   public slots:
    void onReset();
    void onChangedWeight(const QVariant& rows, const QVariant& index,
                         const QVariant& value);

   private:
    int cnt = 3;
    int sum_weight;
    QVector<QVector<int>> m_weights;
};