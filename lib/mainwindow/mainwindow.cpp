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

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), m_ui(new Ui::MainWindow), m_tool_group(this) {
    m_ui->setupUi(this);

    m_ui->toolBar->addActions(m_ui->menuFile->actions());

    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuTools->actions());

    m_ui->toolBar->addSeparator();
    m_ui->toolBar->addActions(m_ui->menuView->actions());

    connect(m_ui->actionAbout, &QAction::triggered, this,
            &MainWindow::aboutSlots);

    connect(m_ui->actionHelp, &QAction::triggered, this,
            &MainWindow::helpSlots);
}

MainWindow::~MainWindow() {
    delete m_ui;
}

/* СЛОТЫ */

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
