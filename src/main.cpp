#include "../lib/common/state.hpp"
#include "../lib/mainwindow/mainwindow.hpp"
#include "../lib/signalcontroller/signalcontroller.hpp"

#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    SignalController controller;
    StateSingleton::instance().setController(&controller);
    MainWindow view;
    view.show();
    return QApplication::exec();
}
