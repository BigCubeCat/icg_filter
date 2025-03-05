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
    virtual std::string name() const;
    /// применение фильтра
    void apply(QImage& image);
    /// возращает конфиг по умолчанию
    virtual QJsonObject config() const;
};
