#include "mainwindow.hpp"
#include <qlogging.h>
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFormLayout>
#include <QMessageBox>
#include <QSpinBox>

#include "../about/about.hpp"
#include "../common/state.hpp"
#include "../help/help.hpp"

MainWindow::MainWindow(QWidget* parent, SignalController* controller)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow),
      m_controller(controller),
      m_config_widget(this),
      m_view(this),
      m_tool_group(this) {
    m_ui->setupUi(this);

    m_ui->dockLayout->addWidget(&m_config_widget);
    m_ui->scrollArea->viewport()->setStyleSheet(
        "background-image: url(assets/background.png);"
        "background-position: center;"
        "background-repeat: no-repeat;");

    m_ui->scrollArea->setWidget(&m_view);
    m_ui->toolBar->addActions(m_ui->menuFile->actions());
    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuZoom->actions());
    m_ui->toolBar->addSeparator();

    /* SETUP UI */
    connect(m_ui->actionAbout, &QAction::triggered, this,
            &MainWindow::aboutSlots);
    connect(m_ui->actionHelp, &QAction::triggered, this,
            &MainWindow::helpSlots);
    connect(m_ui->actionConfig, &QAction::triggered, this,
            &MainWindow::toggleSideBar);
    connect(m_ui->dockWidget, &QDockWidget::visibilityChanged,
            m_ui->actionConfig, &QAction::setChecked);

    // connect IO actions
    connect(m_ui->actionOpen, &QAction::triggered, controller,
            &SignalController::openFile);
    connect(m_ui->actionSave, &QAction::triggered, controller,
            &SignalController::saveFile);
    connect(controller, &SignalController::saveFileSignal, this,
            &MainWindow::updateFilename);
    connect(controller, &SignalController::openFileSignal, this,
            &MainWindow::updateFilename);

    auto& state = StateSingleton::instance();
    m_im = state.imageProcessor();
    m_fp = state.imageProcessor();
    connect(m_im, &ImageProcessor::rerender, &m_view, &ImageView::updateImage);
}

MainWindow::~MainWindow() {
    delete m_ui;
}

/* СЛОТЫ */

void MainWindow::toggleSideBar(bool visible) {
    if (visible) {
        m_ui->dockWidget->show();
    } else {
        m_ui->dockWidget->hide();
    }
}

void MainWindow::aboutSlots() {
    auto about_dialog = AboutDialog(this);
    about_dialog.exec();
}

void MainWindow::helpSlots() {
    auto help_dialog = HelpDialog(this);
    help_dialog.exec();
}

void MainWindow::updateFilename() {
    auto& state = StateSingleton::instance();
    setWindowTitle("ICG_Filter [" + m_fp->name() + "]");
}

void MainWindow::toggleSaved(bool saved) {
    auto& state = StateSingleton::instance();
    auto filename_list =
        QString::fromStdString(state.fileProcessor()->filename()).split("/");
    auto filename = filename_list.at(filename_list.size() - 1);
    if (saved) {
        filename += " *";
    }
    setWindowTitle("ICG_Filter [" + filename + "]");
}
