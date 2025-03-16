#include "../lib/mainwindow/mainwindow.hpp"
#include "../lib/signalcontroller/signalcontroller.hpp"
#include "filters.hpp"
#include "imageprocessor.hpp"
#include "procs/sepia/sepia_filter.hpp"

/// Фильтры
#include "procs/alpha/alpha.hpp"
#include "procs/mirror/mirror.hpp"
#include "procs/rotate/rotate.hpp"
#include "procs/sepia/sepia_filter.hpp"
///

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QWidget>
#include <memory>

#include "WeightMatrix.hpp"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:qml/components");
    qmlRegisterType<WeightMatrix>("weightMatrixModel", 1, 0,"WeightMatrixModel");
    FiltersFactory factory{};

    factory.register_filter("sepia", std::make_shared<SepiaFilter>());
    factory.register_filter("mirror", std::make_shared<MirrorFilter>());
    factory.register_filter("rotate", std::make_shared<RotateFilter>());
    factory.register_filter("alpha", std::make_shared<AlphaFilter>());

    ImageProcessor image_processor{};
    FileProcessor file_processor(image_processor);
    SignalController controller{&file_processor, &image_processor};

    MainWindow view(nullptr, &controller, &image_processor, &file_processor,
                    &factory);

    view.show();
    return QApplication::exec();
}
