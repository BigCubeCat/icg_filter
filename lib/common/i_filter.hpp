#pragma once

#include <string>

#include <QImage>
#include <QJsonObject>

/*!
 * Интерфейс фильтра
*/
class IFilter {
   public:
    /// возращает уникальное имя фильтра
    virtual std::string name() const = 0;
    /// применение фильтра
    virtual void apply(QImage& image) = 0;
    /// возращает конфиг по умолчанию
    virtual QJsonObject json() const = 0;
};
