#pragma once

#include <QActionGroup>
#include <QMainWindow>

#include "../configwidget/configwidget.hpp"
#include "../imageview/imageview.hpp"

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

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    Ui::MainWindow* m_ui;
    ConfigWidget m_config_widget;
    ImageView m_view;

    QActionGroup m_tool_group;

    std::string m_filename;
    std::string m_format = "PNG";

    void askFilename();
};
