#pragma once

#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include <QThread>
#include "imageprocessor.hpp"

/// Класс-работник, выполняющий задачи в потоке
class ImageWorker : public QObject {
    Q_OBJECT
   public:
    explicit ImageWorker(ImageProcessor* processor, QObject* parent = nullptr)
        : QObject(parent), m_processor(processor) {}

   private:
    ImageProcessor* m_processor;
    bool m_running = true;

   public slots:
    void process(IFilter* filter);
    void stop() { m_running = false; }

   signals:
    void finished();
};
