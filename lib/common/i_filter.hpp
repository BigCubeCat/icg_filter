#pragma once

#include <qobject.h>
#include <qtmetamacros.h>
#include <QImage>

enum EFilterType {
    kBasic = 0,  // поворот, зеркало и тп
    kPixel = 1,
    kMatrix = 2
};

/*!
 * Интерфейс фильтра
*/
class IFilter : public QObject {
    Q_OBJECT
   public:
    /// возращает уникальное имя фильтра
    virtual QString name() const = 0;
    /// применение фильтра
    virtual void apply(QImage& image) = 0;
    /// возращает конфиг по умолчанию
    virtual QString qml_path() const = 0;
    /// возращает класс филтра для меню
    virtual EFilterType type() const = 0;

   signals:
    /// сигнал, посылаемый компонентом после окончания обработки изображения
    void done();
};
