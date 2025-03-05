#pragma once

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
    std::string format() const { return m_filename; }
    std::string folder() const { return m_filename; }

   private:
    std::string m_name;
    std::string m_filename;
    std::string m_file_format;
    std::string m_folder;

    ImageProcessor& m_processor;

   public slots:
    void setFilename(const QString& filename);
    void nextImageInFolder();
};
