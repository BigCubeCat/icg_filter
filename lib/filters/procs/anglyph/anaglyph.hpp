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
    Q_PROPERTY(int offset READ getOffset WRITE setOffset NOTIFY offsetChanged())
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
    int getOffset() const { return m_offset; }

    void setOffset(int offset) {
        m_offset = offset;
    }

   signals:
    void imagePathChanged(const QString& path);
    void offsetChanged();

   private:
    QString m_imagePath = "";
    int m_offset = 0;

   public:
    void apply([[maybe_unused]] QImage& image) override;
};
