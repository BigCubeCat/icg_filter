#include "signalcontroller.hpp"
#include <qlogging.h>

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

void SignalController::applyFilterSlot() {}

void SignalController::openFile() {
    auto file_name = QFileDialog::getOpenFileName(
        nullptr, tr("Open Image"), QDir::homePath(),
        tr("Image Files (*.png *.jpg *.bmp)"), nullptr);
    qDebug() << "file name";
    m_fp->setFilename(file_name);
    qDebug() << "file name";
    emit openFileSignal();
}

void SignalController::saveFile() {
    qDebug() << "save";
    auto img = m_im->image();
    if (img.width() == 0 || img.height() == 0) {
        QMessageBox::critical(nullptr, "Image is empty", "Open image first!");
        return;
    }
    auto filename = m_fp->filename();
    if (filename == "") {
        auto file_name = QFileDialog::getSaveFileName(
            nullptr, tr("Save Image"), QDir::homePath(),
            tr("png file (*.png);; jpg file (*.jpg);; bmp file (*.bmp)"),
            nullptr);
        if (file_name.isEmpty()) {
            return;
        }
        m_fp->setFilename(file_name);
    }
    m_im->save(filename, m_fp->format());
    emit saveFileSignal();
}

void SignalController::saveAsFile() {
    qDebug() << "save as";
    auto file_name = QFileDialog::getSaveFileName(
        nullptr, tr("Save Image"), QDir::homePath(),
        tr("png file (*.png);; jpg file (*.jpg);; bmp file (*.bmp)"), nullptr);
    if (file_name.isEmpty()) {
        return;
    }
    m_fp->setFilename(file_name);
    saveFile();
}

void SignalController::newImage() {
    emit newImageSignal();
}
