#include "fileprocessor.hpp"

#include <QDebug>
#include <QFileInfo>

FileProcessor::FileProcessor(ImageProcessor& proc) : m_processor(proc) {}

void FileProcessor::setFilename(const QString& filename) {
    QFileInfo file_info(filename);
    m_filename = filename.toStdString();
    m_folder = file_info.absolutePath().toStdString();
    m_file_format = file_info.completeSuffix().toStdString();
    m_name = filename.split("/").last().toStdString();

    qDebug() << "name=" << m_name;
    qDebug() << "folder=" << m_folder;
    qDebug() << "file=" << m_filename;
    qDebug() << "format=" << m_file_format;

    m_processor.setImage(QImage(filename));
}

void FileProcessor::nextImageInFolder() {}
