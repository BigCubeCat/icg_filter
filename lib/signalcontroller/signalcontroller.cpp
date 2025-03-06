#include "signalcontroller.hpp"
#include <qlogging.h>

#include "../common/state.hpp"

#include <QDir>
#include <QFileDialog>

void SignalController::applyFilterSlot() {}

void SignalController::openFile() {
    auto& state = StateSingleton::instance();
    auto file_name = QFileDialog::getOpenFileName(
        nullptr, tr("Open Image"), QDir::homePath(),
        tr("Image Files (*.png *.jpg *.bmp)"), nullptr);
    auto* fp = state.fileProcessor();
    fp->setFilename(file_name);
    emit openFileSignal();
}

void SignalController::saveFile() {
    auto& state = StateSingleton::instance();

    auto* imp = state.imageProcessor();
    auto* fp = state.fileProcessor();

    auto img = imp->image();
    if (img.width() == 0 || img.height() == 0) {
        // TODO(bigcubecat): show error
        return;
    }
    auto filename = fp->filename();
    if (filename == "") {
        auto file_name = QFileDialog::getSaveFileName(
            nullptr, tr("Save Image"), QDir::homePath(),
            tr("png file (*.png);; jpg file (*.jpg);; bmp file (*.bmp)"),
            nullptr);
        if (file_name.isEmpty()) {
            return;
        }
        fp->setFilename(file_name);
    }
    emit saveFileSignal();
}

void SignalController::saveAsFile() {
    auto& state = StateSingleton::instance();
    auto* fp = state.fileProcessor();
    auto file_name = QFileDialog::getSaveFileName(
        nullptr, tr("Save Image"), QDir::homePath(),
        tr("png file (*.png);; jpg file (*.jpg);; bmp file (*.bmp)"), nullptr);
    if (file_name.isEmpty()) {
        return;
    }
    fp->setFilename(file_name);
    saveFile();
}

void SignalController::newImage() {
    emit newImageSignal();
}
