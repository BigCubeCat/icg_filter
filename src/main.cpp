#include <QApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QWidget>
#include <memory>

#include "WeightMatrix.hpp"
#include "filters.hpp"
#include "imageprocessor.hpp"
#include "mainwindow.hpp"
#include "procs/bw_ordered_dithering/bw_od.hpp"
#include "signalcontroller.hpp"


/// Фильтры
#include "procs/alpha/alpha.hpp"
#include "procs/black_white/black_white_filter.hpp"
#include "procs/blur/blur.hpp"
#include "procs/emboss/emboss.hpp"
#include "procs/inversion/inversion.hpp"
#include "procs/mirror/mirror.hpp"
#include "procs/rotate/rotate.hpp"
#include "procs/sepia/sepia_filter.hpp"
#include "procs/sharp/sharpness.hpp"

#include "WeightMatrix.hpp"
#include "procs/FloydSteinbergFilter/FloydSteinbergFilter.hpp"
#include "procs/anglyph/anaglyph.hpp"
#include "procs/aqua/aquarel.hpp"
#include "procs/gamma/gamma.hpp"
#include "procs/ordered_dithering/OrderedDitheringFilter.hpp"
#include "procs/roberts/RobertsFilter.hpp"
#include "procs/sobel/SobelsFilter.hpp"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:qml/components");
    qmlRegisterType<WeightMatrix>("weightMatrixModel", 1, 0,
                                  "WeightMatrixModel");
    FiltersFactory factory{};

    auto emboss_ptr = std::make_shared<EmbossFilter>();
    factory.register_filter(emboss_ptr->name().toStdString(), emboss_ptr);
    auto sepia_ptr = std::make_shared<SepiaFilter>();
    factory.register_filter(sepia_ptr->name().toStdString(), sepia_ptr);
    auto mirror_ptr = std::make_shared<MirrorFilter>();
    factory.register_filter(mirror_ptr->name().toStdString(), mirror_ptr);
    auto rotate_ptr = std::make_shared<RotateFilter>();
    factory.register_filter(rotate_ptr->name().toStdString(), rotate_ptr);
    auto alpha_ptr = std::make_shared<AlphaFilter>();
    factory.register_filter(alpha_ptr->name().toStdString(), alpha_ptr);
    auto emb_ptr = std::make_shared<EmbossFilter>();
    factory.register_filter(emb_ptr->name().toStdString(), emb_ptr);
    auto bw_ptr = std::make_shared<BlackWhiteFilter>();
    factory.register_filter(bw_ptr->name().toStdString(), bw_ptr);
    auto inv_ptr = std::make_shared<InversionFilter>();
    factory.register_filter(inv_ptr->name().toStdString(), inv_ptr);
    auto blur_ptr = std::make_shared<BlurFilter>();
    factory.register_filter(blur_ptr->name().toStdString(), blur_ptr);
    auto sharp_ptr = std::make_shared<SharpnessFilter>();
    factory.register_filter(sharp_ptr->name().toStdString(), sharp_ptr);
    auto bw_ordered_dithering_filter_ptr =
        std::make_shared<BWOrderedDitheringFilter>();
    factory.register_filter(bw_ordered_dithering_filter_ptr->name().toStdString(),
                            bw_ordered_dithering_filter_ptr);
    auto anaglyph_ptr = std::make_shared<AnaglyphFilter>();
    factory.register_filter(anaglyph_ptr->name().toStdString(), anaglyph_ptr);
    auto gamma_ptr = std::make_shared<GammaCorrectionFiter>();
    factory.register_filter(gamma_ptr->name().toStdString(), gamma_ptr);
    auto roberts_ptr = std::make_shared<RobertsFilter>();
    factory.register_filter(roberts_ptr->name().toStdString(), roberts_ptr);
    auto sobels_ptr = std::make_shared<SobelsFilter>();
    factory.register_filter(sobels_ptr->name().toStdString(), sobels_ptr);
    auto floyd_steinberg_filter_ptr = std::make_shared<FloydSteinbergFilter>();
    factory.register_filter(floyd_steinberg_filter_ptr->name().toStdString(), floyd_steinberg_filter_ptr);
    auto ordered_dithering_filter_ptr = std::make_shared<OrderedDitheringFilter>();
    factory.register_filter(ordered_dithering_filter_ptr->name().toStdString(), ordered_dithering_filter_ptr);
    auto aquarel_ptr = std::make_shared<aquarel>();
    factory.register_filter(aquarel_ptr->name().toStdString(), aquarel_ptr);

    ImageProcessor image_processor(&mutex, &condition_variable);

    FileProcessor file_processor(image_processor);
    SignalController controller{&file_processor, &image_processor};

    MainWindow view(nullptr, &controller, &image_processor, &file_processor,
                    &factory);

    view.show();
    QApplication::exec();
    condition_variable.notify_one();
    image_processor.is_ready();

    return 0;
}
