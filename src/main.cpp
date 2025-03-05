#include "../lib/common/state.hpp"
#include "../lib/mainwindow/mainwindow.hpp"
#include "../lib/signalcontroller/signalcontroller.hpp"
#include "imageprocessor.hpp"

#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    SignalController controller;
    ImageProcessor image_processor(nullptr);
    FileProcessor file_processor(image_processor);

    auto& state = StateSingleton::instance();
    state.setController(&controller);
    state.setImageProcessor(&image_processor);
    state.setFileProcessor(&file_processor);

    MainWindow view(nullptr, &controller);

    view.show();
    return QApplication::exec();
}
