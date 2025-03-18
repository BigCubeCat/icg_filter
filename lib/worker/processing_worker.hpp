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
    explicit ImageWorker(std::mutex* mut, std::condition_variable* cond,
                         ImageProcessor* processor, QObject* parent = nullptr)
        : QObject(parent),
          m_mutex_ptr(mut),
          m_cond_var_ptr(cond),
          m_processor(processor) {}

   private:
    std::mutex* m_mutex_ptr;
    std::condition_variable* m_cond_var_ptr;

    ImageProcessor* m_processor;

    bool m_running = true;

   public slots:
    void process();
    void stop() { m_running = false; }

   signals:
    void finished();
};
