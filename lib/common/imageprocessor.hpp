#pragma once

#include <qimage.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include "i_filter.hpp"

const float kZoomStep = 0.02F;

/*!
 * Объект, отвечающий за работу над изобржением
  */
class ImageProcessor : public QObject {
    Q_OBJECT
   public:
    explicit ImageProcessor();

    void filter(const std::string& name);

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
    QImage m_original;
    QImage m_edited;

    double m_current_zoom = 1.0F;
    bool m_saved;
    bool m_has_edited = false;

    void updateImageSize();
    void zoomHandler(int old_zoom);

   public slots:
    void applyFilter(IFilter* filter);
    void zoomIn();
    void zoomOut();
    void zoomReset();
};
