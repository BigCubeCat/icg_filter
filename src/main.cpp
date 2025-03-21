#include "../lib/mainwindow/mainwindow.hpp"
#include "../lib/signalcontroller/signalcontroller.hpp"
#include "filters.hpp"
#include "imageprocessor.hpp"
#include "procs/emboss/emboss.hpp"
#include "procs/sepia/sepia_filter.hpp"

/// Фильтры
#include "procs/alpha/alpha.hpp"
#include "procs/mirror/mirror.hpp"
#include "procs/rotate/rotate.hpp"
#include "procs/sepia/sepia_filter.hpp"
#include "procs/blur/blur.hpp"
#include "procs/black_white/black_white_filter.hpp"
#include "procs/inversion/inversion.hpp"
#include "procs/sharp/sharpness.hpp"

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
    qmlRegisterType<WeightMatrix>("weightMatrixModel", 1, 0,
                                  "WeightMatrixModel");
    FiltersFactory factory{};

    factory.register_filter("sepia", std::make_shared<SepiaFilter>());
    factory.register_filter("mirror", std::make_shared<MirrorFilter>());
    factory.register_filter("rotate", std::make_shared<RotateFilter>());
    factory.register_filter("alpha", std::make_shared<AlphaFilter>());
    factory.register_filter("emboss", std::make_shared<EmbossFilter>());
  
    auto sepia_ptr = std::make_shared<SepiaFilter>();
    factory.register_filter(sepia_ptr->name().toStdString(), sepia_ptr );
    auto mirror_ptr = std::make_shared<SepiaFilter>();
    factory.register_filter(mirror_ptr->name().toStdString(), mirror_ptr );
    auto rotate_ptr = std::make_shared<SepiaFilter>();
    factory.register_filter(rotate_ptr->name().toStdString(), rotate_ptr );
    auto alpha_ptr = std::make_shared<SepiaFilter>();
    factory.register_filter(alpha_ptr->name().toStdString(), alpha_ptr );
    auto bw_ptr = std::make_shared<BlackWhiteFilter>();
    factory.register_filter(bw_ptr->name().toStdString(), bw_ptr);
    auto inv_ptr = std::make_shared<InversionFilter>();
    factory.register_filter(inv_ptr->name().toStdString(), inv_ptr);
    auto blur_ptr = std::make_shared<BlurFilter>();
    factory.register_filter(blur_ptr->name().toStdString(), blur_ptr);
    auto sharp_ptr = std::make_shared<SharpnessFilter>();
    factory.register_filter(sharp_ptr->name().toStdString(), sharp_ptr);
    


    ImageProcessor image_processor{};
    FileProcessor file_processor(image_processor);
    SignalController controller{&file_processor, &image_processor};

    MainWindow view(nullptr, &controller, &image_processor, &file_processor,
                    &factory);

    view.show();
    return QApplication::exec();
}
