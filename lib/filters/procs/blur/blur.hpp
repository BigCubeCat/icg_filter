#pragma once
#include "i_filter.hpp"

class blur : public IFilter {
    Q_OBJECT
   public:
    blur();
    QString name() const override;
    void apply(QImage& image) override;
    QString qml_path() const override;
    EFilterType type() const override;

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
