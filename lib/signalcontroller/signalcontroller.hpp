#pragma once

#include <qtmetamacros.h>
#include <QObject>

/*!
 * \brief перенаправляет сигналы на нужные слоты. позволяет соеденить model и view
  */
class SignalController : public QObject {
    Q_OBJECT
   public:
    explicit SignalController() = default;

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

};
