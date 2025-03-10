#include "../lib/mainwindow/mainwindow.hpp"
#include "../lib/signalcontroller/signalcontroller.hpp"
#include "filters.hpp"
#include "imageprocessor.hpp"
#include "procs/sepia/sepia_filter.hpp"
#include "procs/black_white/black_white_filter.hpp"
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

    auto sepia_ptr = std::make_shared<SepiaFilter>();
    factory.register_filter(sepia_ptr->name().toStdString(), sepia_ptr );
    auto bw_ptr = std::make_shared<BlackWhiteFilter>();
    factory.register_filter(bw_ptr->name().toStdString(), bw_ptr);

    ImageProcessor image_processor{};
    FileProcessor file_processor(image_processor);
    SignalController controller{&file_processor, &image_processor};

    MainWindow view(nullptr, &controller, &image_processor, &file_processor,
                    &factory);

    view.show();
    return QApplication::exec();
}
