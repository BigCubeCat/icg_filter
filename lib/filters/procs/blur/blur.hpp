#pragma once
#include "i_filter.hpp"

class BlurFilter : public IFilter {
    Q_OBJECT
   public:
    BlurFilter(int cnt = 3, int off = 0);
    QString name() const override { return "blur"; }
    void apply(QImage& image) override;
    QString qml_path() const override { return "qrc:/qml/filters/blur.qml"; }
    EFilterType type() const override { return kMatrix; }

   signals:
    void set_weight(const QVariant& index, const QVariant& value);

   public slots:
    void onChangedSize(const QVariant& size);
    void onChangedWeight(const QVariant& rows, const QVariant& index,
                         const QVariant& value);

   private:
    int size;
    int sum_weight;
    QVector<QVector<int>> m_weights;
};
