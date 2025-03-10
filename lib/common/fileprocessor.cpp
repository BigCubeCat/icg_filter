#include "fileprocessor.hpp"
#include <qlogging.h>

#include <QDebug>
#include <QFileInfo>

FileProcessor::FileProcessor(ImageProcessor& proc) : m_processor(proc) {}

void FileProcessor::open_dir(const std::string& dir) {
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.bmp";
    m_current_dir = QDir(QString::fromStdString(dir));
    m_images = m_current_dir.entryInfoList(filters,
                                           QDir::Files | QDir::NoDotAndDotDot);

    qDebug() << m_images;
}

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

    open_dir(m_folder);

    m_processor.setImage(QImage(filename));
}

void FileProcessor::nextImageInFolder() {}
void FileProcessor::prevImageInFolder() {}
