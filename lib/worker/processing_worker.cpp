#include "processing_worker.hpp"
#include <qlogging.h>
#include <mutex>

void ImageWorker::process() {
    while (m_running) {
        std::unique_lock lk(*m_mutex_ptr);
        m_cond_var_ptr->wait(lk, [this] { return m_processor->ready(); });
        m_processor->apply();
        emit finished();
    }
}
