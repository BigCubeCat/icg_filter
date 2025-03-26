#pragma once

#include "i_filter.hpp"

class GammaCorrectionFiter : public IFilter {
    Q_OBJECT
    Q_PROPERTY(double gamma READ getGamma WRITE setGamma NOTIFY gammaChanged())
   public:
    QString name() const override { return "gamma"; }
    void apply(QImage& image) override;
    QString qml_path() const override { return "qrc:/qml/filters/gamma.qml"; }
    EFilterType type() const override { return kBasic; }
    Q_INVOKABLE double getGamma() const;
    Q_INVOKABLE void setGamma(const QVariant& gamma);
   signals:
    void gammaChanged();

   private:
    double m_gamma = 1.0;
};
