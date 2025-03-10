#pragma once

#include <qtmetamacros.h>
#include <QObject>
#include "../common/fileprocessor.hpp"
#include "../common/imageprocessor.hpp"

/*!
 * \brief перенаправляет сигналы на нужные слоты. позволяет соеденить model и view
  */
class SignalController : public QObject {
    Q_OBJECT
   public:
    explicit SignalController(FileProcessor* fp, ImageProcessor* im)
        : m_fp(fp), m_im(im) {}

   signals:
    void applyFilterSignal();
    void saveFileSignal();
    void openFileSignal();
    void newImageSignal();

   public slots:
    void applyFilterSlot();

    /// открытие файла
    void openFile();
    /// Сохранить файл
    void saveFile();
    /// Сохранить как
    void saveAsFile();

    void newImage();

   private:
    FileProcessor* m_fp;
    ImageProcessor* m_im;
};
