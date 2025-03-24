#pragma once

#include <qfuturewatcher.h>
#include <qimage.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include "i_filter.hpp"

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

    bool ready() const { return m_need_process; }

    void is_ready() { m_need_process = true; }

    void apply();

   signals:
    void rerender();
    void saved(bool is_saved);

    void process(IFilter* filter);

   private:
    QFutureWatcher<QImage> m_watcher;

    IFilter* m_filter;

    QImage m_original;
    QImage m_edited;
    QImage m_image;

    bool m_saved;
    bool m_has_edited = false;

    bool m_need_process;

    void done();

   public slots:
    void applyFilter(IFilter* filter);
    void save(const std::string& filename, const std::string& format);

   private slots:
    void onImageProcessed();
};
