#include "fileprocessor.hpp"
#include <qlogging.h>

#include <QDebug>
#include <QFileInfo>

FileProcessor::FileProcessor(ImageProcessor& proc) : m_processor(proc) {}

void FileProcessor::open_dir(const std::string& dir) {
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.bmp" << "*.webp";
    m_current_dir = QDir(QString::fromStdString(dir));
    auto fi = m_current_dir.entryInfoList(filters,
                                          QDir::Files | QDir::NoDotAndDotDot);
    m_image_files.resize(fi.size());
    auto len = fi.size();
    for (auto i = 0; i < len; ++i) {
        m_image_files[i] = fi[i].filePath();
        if (m_image_files[i] == m_filename) {
            m_cursor = i;
        }
        qDebug() << "file: " << m_image_files[i] << "\n";
    }
}

void FileProcessor::setFilename(const QString& filename) {
    QFileInfo file_info(filename);
    m_filename = filename.toStdString();
    m_folder = file_info.absolutePath().toStdString();
    m_file_format = file_info.completeSuffix().toStdString();
    m_name = filename.split("/").last().toStdString();

    open_dir(m_folder);

    m_processor.setImage(QImage(filename));
}

void FileProcessor::nextImageInFolder() {
    m_cursor = (m_cursor + 1) % m_image_files.size();
    move_in_folder();
}

void FileProcessor::prevImageInFolder() {
    m_cursor = (m_image_files.size() + m_cursor - 1) % m_image_files.size();
    move_in_folder();
}

void FileProcessor::move_in_folder() {
    qDebug() << "cursor = " << m_cursor;
    m_filename = m_image_files[m_cursor].toStdString();
    m_file_format =
        QFileInfo(m_image_files[m_cursor]).completeSuffix().toStdString();
    m_name = m_image_files[m_cursor].split("/").last().toStdString();
    qDebug() << m_image_files[m_cursor];
    m_processor.setImage(QImage(m_image_files[m_cursor]));
}
