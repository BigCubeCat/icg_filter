#pragma once

#include <qlogging.h>
#include <qpainter.h>
#include <QImage>
#include <QJsonObject>

#include "i_filter.hpp"

class AnaglyphFilter : public IFilter {
    Q_OBJECT

    Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath NOTIFY
                   imagePathChanged)
   public:
    ~AnaglyphFilter() override = default;

    QString qml_path() const override {
        return QString("qrc:/qml/filters/anaglyph.qml");
    }

    QString name() const override { return "anaglyph"; }

    EFilterType type() const override { return kPixel; }

    QString imagePath() const { return m_imagePath; }

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
    void imagePathChanged(const QString& path);

   private:
    QString m_imagePath;

   public:
    void apply([[maybe_unused]] QImage& image) override;
};
