#include "../lib/mainwindow/mainwindow.hpp"
#include "../lib/signalcontroller/signalcontroller.hpp"
#include "filters.hpp"
#include "imageprocessor.hpp"

/// Фильтры
#include "procs/mirror/mirror.hpp"
#include "procs/sepia/sepia_filter.hpp"
///

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QWidget>
#include <memory>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:qml/components");

    FiltersFactory factory{};

    factory.register_filter("sepia", std::make_shared<SepiaFilter>());
    factory.register_filter("mirror", std::make_shared<MirrorFilter>());

    ImageProcessor image_processor{};
    FileProcessor file_processor(image_processor);
    SignalController controller{&file_processor, &image_processor};

    MainWindow view(nullptr, &controller, &image_processor, &file_processor,
                    &factory);

    view.show();
    return QApplication::exec();
}
