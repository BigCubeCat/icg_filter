#include "../lib/mainwindow/mainwindow.hpp"

#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return QApplication::exec();
}
