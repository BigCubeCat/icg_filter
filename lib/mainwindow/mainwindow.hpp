#pragma once

#include <QActionGroup>
#include <QMainWindow>

#include "../imageview/imageview.hpp"
#include "../signalcontroller/signalcontroller.hpp"
#include "fileprocessor.hpp"
#include "i_factory.hpp"
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

    void applyFilter();

    void hideToolbar();

   public:
    explicit MainWindow(QWidget* parent, SignalController* controller,
                        ImageProcessor* im, FileProcessor* fp,
                        IFactory* factory);
    ~MainWindow() override;

   private:
    Ui::MainWindow* m_ui;
    IFactory* m_factory;
    SignalController* m_controller;
    ImageView m_view;

    ImageProcessor* m_im;
    FileProcessor* m_fp;

    IFilter* m_current_filter = nullptr;

    QActionGroup m_tool_group;
    std::vector<QAction> m_filter_actions;

    std::string m_filename;
    std::string m_format = "PNG";

    void connectSlots();
    void registerFilters();
    void filterApplyed();
};
