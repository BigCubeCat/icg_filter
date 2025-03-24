#pragma once

#include <qimage.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <condition_variable>
#include <mutex>
#include "i_filter.hpp"

const float kZoomStep = 0.02F;

/*!
 * Объект, отвечающий за работу над изобржением
  */
class ImageProcessor : public QObject {
    Q_OBJECT
   public:
    explicit ImageProcessor(std::mutex* mut, std::condition_variable* cond);

    void filter(const std::string& name);

    void setSaved(bool saved);
    bool is_saved() const;

    QImage image() const;
    void setImage(QImage new_image);

    float zoomFacor() const { return m_current_zoom; }

    bool ready() const { return m_need_process; }

    void is_ready() {
        m_need_process = true;
        {
            std::lock_guard lk(*m_mutex_ptr);
            m_need_process = true;
        }
        m_cond_var_ptr->notify_one();
    }

    void apply();

   signals:
    void rerender();
    void saved(bool is_saved);
    void zoom(float old_factor, float new_factor);

    void process(IFilter* filter);

   private:
    std::mutex* m_mutex_ptr;
    std::condition_variable* m_cond_var_ptr;

    IFilter* m_filter;

    QImage m_original;
    QImage m_edited;
    QImage m_image;

    double m_current_zoom = 1.0F;
    bool m_saved;
    bool m_has_edited = false;

    bool m_need_process;

    void updateImageSize();
    void zoomHandler(int old_zoom);

   public slots:
    void applyFilter(IFilter* filter);
    void zoomIn();
    void zoomOut();
    void zoomReset();
    void save(const std::string& filename, const std::string& format);
    void done();
    void zoomFit(const QSize& size);
};
