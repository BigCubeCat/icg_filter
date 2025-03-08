#pragma once

#include <qobject.h>
#include <qtmetamacros.h>
#include "i_factory.hpp"

/*!
 * Объект, отвечающий за работу над изобржением
  */
class ImageProcessor : public QObject {
    Q_OBJECT
   public:
    explicit ImageProcessor(IFactory* factory);

    void filter(const std::string& name, const QJsonObject& args);

    void setSaved(bool saved);
    bool is_saved() const;

    QImage image() const;
    void setImage(QImage new_image);

   signals:
    void rerender();
    void saved(bool is_saved);

   private:
    IFactory* m_factory;
    QImage m_original;
    QImage m_edited;

    double m_current_zoom = 1.0F;
    bool m_saved;
    bool m_has_edited = false;
};
