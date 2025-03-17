#pragma once

#include <qdir.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include "imageprocessor.hpp"

/*!
 * Объект, отвечающий за работу с фалйлами
  */
class FileProcessor : public QObject {
    Q_OBJECT
   public:
    explicit FileProcessor(ImageProcessor& proc);

    std::string name() const { return m_name; }
    std::string filename() const { return m_filename; }
    std::string format() const { return m_file_format; }
    std::string folder() const { return m_folder; }

   private:
    std::string m_name;
    std::string m_filename;
    std::string m_file_format;
    std::string m_folder;

    QDir m_current_dir;
    std::vector<QString> m_image_files;
    int m_cursor = 0;

    ImageProcessor& m_processor;

    void move_in_folder();
    void open_dir(const std::string& dir);

   public slots:
    void setFilename(const QString& filename);
    void nextImageInFolder();
    void prevImageInFolder();
};
