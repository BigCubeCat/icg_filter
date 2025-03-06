#pragma once

#include <QActionGroup>
#include <QMainWindow>

#include "../configwidget/configwidget.hpp"
#include "../imageview/imageview.hpp"
#include "../signalcontroller/signalcontroller.hpp"
#include "fileprocessor.hpp"
#include "imageprocessor.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
   private slots:
    void aboutSlots();
    void helpSlots();
    void toggleSideBar(bool visible);
    void updateFilename();
    void toggleSaved(bool saved);

   public:
    explicit MainWindow(QWidget* parent, SignalController* controller);
    ~MainWindow() override;

   private:
    Ui::MainWindow* m_ui;
    SignalController* m_controller;
    ConfigWidget m_config_widget;
    ImageView m_view;

    ImageProcessor* m_im;
    FileProcessor* m_fp;

    QActionGroup m_tool_group;

    std::string m_filename;
    std::string m_format = "PNG";

    void connectSlots();
};
