#include "mainwindow.hpp"
#include <qlogging.h>
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFormLayout>
#include <QMessageBox>
#include <QSpinBox>

#include "../about/about.hpp"
#include "../help/help.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow),
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
    m_ui->toolBar->addActions(m_ui->menuTools->actions());

    m_ui->toolBar->addSeparator();

    connect(m_ui->actionAbout, &QAction::triggered, this,
            &MainWindow::aboutSlots);

    connect(m_ui->actionHelp, &QAction::triggered, this,
            &MainWindow::helpSlots);

    /// настройка SideBar
    connect(m_ui->actionConfig, &QAction::triggered, this,
            &MainWindow::toggleSideBar);
    connect(m_ui->dockWidget, &QDockWidget::visibilityChanged,
            m_ui->actionConfig, &QAction::setChecked);
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

void MainWindow::askFilename() {
    QString selected_filter;
    QString file_name = QFileDialog::getSaveFileName(
        //
        this, tr("Save Image"), QDir::homePath(),
        tr("png file (*.png);; jpg file (*.jpg);; bmp file (*.bmp)"),
        &selected_filter, QFileDialog::DontUseNativeDialog);
    qDebug() << selected_filter << "|";
    m_format = selected_filter.split(" ").at(0).toStdString();
    if (!file_name.isEmpty()) {
        m_filename = file_name.toStdString();
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
