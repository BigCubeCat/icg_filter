/********************************************************************************
** Form generated from reading UI file 'configwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGWIDGET_H
#define UI_CONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigWidget
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *applyButton;

    void setupUi(QWidget *ConfigWidget)
    {
        if (ConfigWidget->objectName().isEmpty())
            ConfigWidget->setObjectName("ConfigWidget");
        ConfigWidget->resize(181, 409);
        verticalLayout = new QVBoxLayout(ConfigWidget);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(ConfigWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 161, 358));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        applyButton = new QPushButton(ConfigWidget);
        applyButton->setObjectName("applyButton");

        verticalLayout->addWidget(applyButton);


        retranslateUi(ConfigWidget);

        QMetaObject::connectSlotsByName(ConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *ConfigWidget)
    {
        ConfigWidget->setWindowTitle(QCoreApplication::translate("ConfigWidget", "Form", nullptr));
        applyButton->setText(QCoreApplication::translate("ConfigWidget", "APPLY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigWidget: public Ui_ConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGWIDGET_H
