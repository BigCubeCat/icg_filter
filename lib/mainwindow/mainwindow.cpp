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
                       ImageProcessor* im, FileProcessor* fp, IFactory* factory)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow),
      m_factory(factory),
      m_controller(controller),
      m_view(im, this),
      m_im(im),
      m_fp(fp),
      m_tool_group(this) {
    m_ui->setupUi(this);

    m_ui->scrollArea->viewport()->setStyleSheet(
        "background-image: url(assets/background.png);"
        "background-position: center;"
        "background-repeat: no-repeat;");

    m_ui->quickWidget->engine()->addImportPath("qml");

    m_ui->scrollArea->setWidget(&m_view);
    m_ui->toolBar->addActions(m_ui->menuFile->actions());
    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuZoom->actions());
    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuImage->actions());

    connectSlots();
    registerFilters();
}

void MainWindow::connectSlots() {
    /* SETUP UI */
    connect(m_ui->applyButton, &QPushButton::clicked, this,
            &MainWindow::applyFilter);
    connect(m_ui->actionAbout, &QAction::triggered, this,
            &MainWindow::aboutSlots);
    connect(m_ui->actionHelp, &QAction::triggered, this,
            &MainWindow::helpSlots);
    connect(m_ui->actionConfig, &QAction::triggered, this,
            &MainWindow::toggleSideBar);
    connect(m_ui->dockWidget, &QDockWidget::visibilityChanged,
            m_ui->actionConfig, &QAction::setChecked);
    connect(m_ui->actionOpen, &QAction::triggered, m_controller,
            &SignalController::openFile);
    connect(m_ui->actionSave, &QAction::triggered, m_controller,
            &SignalController::saveFile);

    connect(m_ui->actionZoomIn, &QAction::triggered, m_im,
            &ImageProcessor::zoomIn);
    connect(m_ui->actionZoomOut, &QAction::triggered, m_im,
            &ImageProcessor::zoomOut);
    connect(m_ui->actionResetZoom, &QAction::triggered, m_im,
            &ImageProcessor::zoomReset);

    connect(m_controller, &SignalController::saveFileSignal, this,
            &MainWindow::updateFilename);
    connect(m_controller, &SignalController::openFileSignal, this,
            &MainWindow::updateFilename);
    connect(m_controller, &SignalController::openFileSignal, &m_view,
            &ImageView::updateImage);

    connect(m_controller, &SignalController::newImageSignal, &m_view,
            &ImageView::updateImage);
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
    setWindowTitle("ICG_Filter [" + QString::fromStdString(m_fp->name()) + "]");
}

void MainWindow::toggleSaved(bool saved) {
    auto filename_list = QString::fromStdString(m_fp->filename()).split("/");
    auto filename = filename_list.at(filename_list.size() - 1);
    if (saved) {
        filename += " *";
    }
    setWindowTitle("ICG_Filter [" + filename + "]");
}

void MainWindow::applyFilter() {
    if (!m_current_filter) {
        // TODO: show error
        return;
    }
    m_im->applyFilter(m_current_filter);
}

void MainWindow::handleFilterAction() {}

void MainWindow::registerFilters() {
    static std::map<EFilterType, QMenu*> menus = {
        {kPixel, m_ui->menuPixel},
        {kBasic, m_ui->menuBasics},
        {kMatrix, m_ui->menuMatrix},
    };
    auto all_filters = m_factory->all_filters();
    for (auto& filter : all_filters) {
        connect(filter, &IFilter::done, &m_view, &ImageView::updateImage);
        auto* action = new QAction(filter);
        action->setText(filter->name());
        connect(action, &QAction::triggered, this, &MainWindow::filterApplyed);
        menus[filter->type()]->addAction(action);
        m_ui->quickWidget->rootContext()->setContextProperty(
            filter->name(), QVariant::fromValue(filter));
    }
}

void MainWindow::filterApplyed() {
    auto* filter_action = qobject_cast<QAction*>(sender());
    auto* filter = qobject_cast<IFilter*>(filter_action->parent());
    qDebug() << filter->name();
    m_ui->quickWidget->setSource(QUrl(filter->qml_path()));
    m_current_filter = filter;
    // m_im->applyFilter(filter);
}
