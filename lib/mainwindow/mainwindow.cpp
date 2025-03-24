#include "mainwindow.hpp"
#include <qlogging.h>
#include <qqmlengine.h>
#include <QQmlContext>
#include <QtQuickWidgets/QQuickWidget>
#include "i_factory.hpp"
#include "i_filter.hpp"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFormLayout>
#include <QMessageBox>
#include <QSpinBox>
#include <QWidget>
#include <map>

#include "../about/about.hpp"
#include "../help/help.hpp"

MainWindow::MainWindow(QWidget* parent, SignalController* controller,
                       ImageProcessor* im, ImageWorker* worker,
                       FileProcessor* fp, IFactory* factory)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow),
      m_factory(factory),
      m_image_painter(im, this),
      m_controller(controller),
      m_im(im),
      m_worker(worker),
      m_fp(fp),
      m_tool_group(this) {
    m_ui->setupUi(this);

    m_ui->mainLayout->addWidget(&m_image_painter);

    m_ui->quickWidget->engine()->addImportPath("qrc:/qml");

    m_ui->toolBar->addActions(m_ui->menuFile->actions());
    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuZoom->actions());
    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuImage->actions());

    connectSlots();
    registerFilters();
}

void MainWindow::connectSlots() {
    connect(m_worker, &ImageWorker::finished, m_im, &ImageProcessor::done);
    /* SETUP UI */
    connect(m_ui->applyButton, &QPushButton::clicked, this,
            &MainWindow::applyFilter);
    connect(m_ui->actionAbout, &QAction::triggered, this,
            &MainWindow::aboutSlots);
    connect(m_ui->actionHelp, &QAction::triggered, this,
            &MainWindow::helpSlots);
    connect(m_ui->actionConfig, &QAction::triggered, this,
            &MainWindow::toggleSideBar);
    connect(m_ui->actionShowWindowToolbar, &QAction::triggered, this,
            &MainWindow::hideToolbar);
    connect(m_ui->dockWidget, &QDockWidget::visibilityChanged,
            m_ui->actionConfig, &QAction::setChecked);
    connect(m_ui->actionOpen, &QAction::triggered, m_controller,
            &SignalController::openFile);
    connect(m_ui->actionSave, &QAction::triggered, m_controller,
            &SignalController::saveFile);
    connect(m_ui->actionSave_As, &QAction::triggered, m_controller,
            &SignalController::saveAsFile);

    connect(m_ui->actionZoomIn, &QAction::triggered, &m_image_painter,
            &ImagePainter::zoomIn);
    connect(m_ui->actionZoomOut, &QAction::triggered, &m_image_painter,
            &ImagePainter::zoomOut);
    connect(m_ui->actionResetZoom, &QAction::triggered, &m_image_painter,
            &ImagePainter::zoomReset);
    connect(m_ui->actionZoomFit, &QAction::triggered, &m_image_painter,
            &ImagePainter::zoomFit);

    connect(m_controller, &SignalController::saveFileSignal, this,
            &MainWindow::updateFilename);
    connect(m_controller, &SignalController::openFileSignal, this,
            &MainWindow::updateFilename);

    connect(m_controller, &SignalController::openFileSignal, this,
            &MainWindow::updateView);
    connect(m_controller, &SignalController::newImageSignal, this,
            &MainWindow::updateView);
    connect(m_im, &ImageProcessor::rerender, this, &MainWindow::updateView);

    connect(m_ui->actionNextImage, &QAction::triggered, m_fp,
            &FileProcessor::nextImageInFolder);
    connect(m_ui->actionPreviousImage, &QAction::triggered, m_fp,
            &FileProcessor::prevImageInFolder);
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
    auto filename_list = QString::fromStdString(m_fp->filename()).split("/");
    auto filename = filename_list.at(filename_list.size() - 1);
    if (m_im->is_saved()) {
        filename += " *";
    }
    setWindowTitle("ICG_Filter [" + filename + "]");
}

void MainWindow::applyFilter() {
    if (!m_current_filter) {
        QMessageBox::critical(nullptr, "No filter",
                              "Please, choose filter first!");
        return;
    }
    if (!m_im->ready())
        m_im->applyFilter(m_current_filter);
}

void MainWindow::registerFilters() {
    static std::map<EFilterType, QMenu*> menus = {
        {kPixel, m_ui->menuPixel},
        {kBasic, m_ui->menuBasics},
        {kMatrix, m_ui->menuMatrix},
    };
    static std::map<EFilterType, QString> icon_path = {
        {kPixel, "assets/icons/svg/solid/atom.svg"},
        {kBasic, "assets/icons/svg/solid/eye.svg"},
        {kMatrix, "assets/icons/svg/solid/square.svg"},
    };
    auto all_filters = m_factory->all_filters();
    for (auto& filter : all_filters) {
        connect(filter, &IFilter::done, this, &MainWindow::updateView);
        auto* action = new QAction(filter);
        action->setIcon(QIcon(icon_path[filter->type()]));

        action->setText(filter->name());
        connect(action, &QAction::triggered, this, &MainWindow::filterApplyed);
        menus[filter->type()]->addAction(action);
        m_ui->quickWidget->rootContext()->setContextProperty(
            filter->name(), QVariant::fromValue(filter));
    }
    m_ui->toolBar->addActions(m_ui->menuBasics->actions());
    m_ui->toolBar->addActions(m_ui->menuPixel->actions());
    m_ui->toolBar->addActions(m_ui->menuMatrix->actions());
}

void MainWindow::filterApplyed() {
    auto* filter_action = qobject_cast<QAction*>(sender());
    auto* filter = qobject_cast<IFilter*>(filter_action->parent());
    m_ui->quickWidget->setSource(QUrl(filter->qml_path()));
    m_current_filter = filter;
}

void MainWindow::hideToolbar() {
    m_ui->toolBar->setHidden(!m_ui->actionShowWindowToolbar->isChecked());
}

void MainWindow::updateView() {
    m_image_painter.setView(m_im->image());
}
