#pragma once

#include <QActionGroup>
#include <QMainWindow>

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

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    Ui::MainWindow* m_ui;

    QActionGroup m_tool_group;

    std::string m_filename;
    std::string m_format = "PNG";

    void askFilename();
};
