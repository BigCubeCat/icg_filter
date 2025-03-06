#pragma once

#include <qobject.h>
#include <qtmetamacros.h>
#include "i_factory.hpp"

const float kZoomStep = 0.02F;

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

    float zoomFacor() const { return m_current_zoom; }

   signals:
    void rerender();
    void saved(bool is_saved);
    void zoom(float old_factor, float new_factor);

   private:
    IFactory* m_factory;
    QImage m_original;
    QImage m_edited;

    double m_current_zoom = 1.0F;
    bool m_saved;
    bool m_has_edited = false;

    void updateImageSize();
    void zoomHandler(int old_zoom);

   public slots:
    void zoomIn();
    void zoomOut();
    void zoomReset();
};
