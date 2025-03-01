#include "configwidget.hpp"

#include "ui_configwidget.h"

ConfigWidget::ConfigWidget(QWidget* parent)
    : QWidget(parent), m_ui(new Ui::ConfigWidget) {
    m_ui->setupUi(this);
}

void ConfigWidget::updateView() {
    update();
}

ConfigWidget::~ConfigWidget() {
    delete m_ui;
}
