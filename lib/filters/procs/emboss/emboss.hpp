#pragma once

#include <qlogging.h>
#include <QImage>
#include <QJsonObject>

#include "i_filter.hpp"

class EmbossFilter : public IFilter {
    Q_OBJECT
    Q_PROPERTY(int offsetX READ offsetX WRITE setOffsetX NOTIFY offsetChangedX)
    Q_PROPERTY(int offsetY READ offsetY WRITE setOffsetY NOTIFY offsetChangedX)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)

   public:
    ~EmbossFilter() override = default;

    QString qml_path() const override {
        return QString("qrc:/qml/filters/emboss.qml");
    }

    QString name() const override { return "emboss"; }

    EFilterType type() const override { return kMatrix; }

    int offsetX() const { return m_offset_x; }
    int offsetY() const { return m_offset_y; }
    QString color() const { return m_color; }

    void setOffsetX(int value) {
        if (m_offset_x != value) {
            m_offset_x = value;
            emit offsetChangedX(value);
        }
    }

    void setOffsetY(int value) {
        if (m_offset_y != value) {
            m_offset_y = value;
            emit offsetChangedY(value);
        }
    }

    void setColor(const QString& color) {
        if (m_color != color) {
            m_color = color;
            emit colorChanged(color);
        }
    }

   signals:
    void offsetChangedX(int value);
    void offsetChangedY(int value);
    void colorChanged(const QString& color);

   private:
    int m_offset_x = 0;
    int m_offset_y = 0;
    QString m_color = "#888888";

   public:
    void apply([[maybe_unused]] QImage& image) override;
};
