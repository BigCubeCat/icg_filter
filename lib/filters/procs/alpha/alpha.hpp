#pragma once

#include <qlogging.h>
#include <qpainter.h>
#include <QImage>
#include <QJsonObject>

#include "i_filter.hpp"

class AlphaFilter : public IFilter {
    Q_OBJECT
    Q_PROPERTY(int percent READ percent WRITE setPercent NOTIFY percentChanged)
    Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath NOTIFY
                   imagePathChanged)
    Q_PROPERTY(int variant READ variant WRITE setVariant NOTIFY variantChanged)

   public:
    ~AlphaFilter() override = default;

    QString qml_path() const override {
        return QString("qml/filters/alpha.qml");
    }

    QString name() const override { return "alpha"; }

    EFilterType type() const override { return kPixel; }

    QString imagePath() const { return m_imagePath; }

    double percent() const { return m_percent; }

    void setPercent(int value) {
        if (m_percent != value) {
            m_percent = value;
            emit percentChanged(value);
        }
    }

    int variant() const { return m_variant; }

    void setVariant(int variant) {
        qDebug() << "variant = " << variant;
        if (m_variant != variant) {
            m_variant = variant;
            emit variantChanged(variant);
        }
    }

    void setImagePath(const QString& path) {
        if (m_imagePath == path)
            return;

        QString clean_path = QUrl(path).toLocalFile();

        m_imagePath = clean_path;
        emit imagePathChanged(clean_path);

        // Здесь можно работать с файлом
        qDebug() << "Selected image path:" << clean_path;
    }

   signals:
    void percentChanged(double value);
    void imagePathChanged(const QString& path);
    void variantChanged(double variant);

   private:
    int m_percent = 0;
    QString m_imagePath;
    int m_variant = 0;

    void apply_tiling(QImage& image, const QImage& second,
                      QPainter* painter_ptr);

    void apply(QImage& image, const QImage& second, const QPoint& start,
               QPainter* painter_ptr);

   public:
    void apply([[maybe_unused]] QImage& image) override;
};
